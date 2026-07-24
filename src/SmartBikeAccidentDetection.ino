
#include <Wire.h>
#include <TinyGPSPlus.h>
#include <Adafruit_NeoPixel.h>

// -------------------- Hardware Pins --------------------
#define BUZZER_PIN   25
#define BUTTON_PIN   4
#define LED_PIN      2
#define LED_COUNT    1

// -------------------- GPS & GSM Pins --------------------
#define GPS_RX  17
#define GPS_TX  16
#define SIM800_RX 26
#define SIM800_TX 27

// -------------------- Objects --------------------
TinyGPSPlus gps;
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

// GPS on UART2, SIM800L on UART1
HardwareSerial gpsSerial(2);
HardwareSerial sim800(1);

// -------------------- Constants --------------------
#define MPU6050_ADDR 0x68
#define IMPACT_THRESHOLD 2.5   // g
#define TILT_THRESHOLD   60    // degrees
const char PHONE_NUMBER[] = "+919489933127"; // Replace with actual number

// -------------------- State Machine --------------------
enum State {
  STATE_MONITORING,
  STATE_IMPACT,
  STATE_VERIFY_TILT,
  STATE_VERIFY_STILLNESS,
  STATE_COUNTDOWN,
  STATE_SEND_SMS,
  STATE_WAIT_RESET
};

State currentState = STATE_MONITORING;

// -------------------- Variables --------------------
float lastLat = 0.0, lastLon = 0.0;
unsigned long stateStartTime = 0;

// -------------------- MPU6050 Raw Read Functions --------------------
void mpuWrite(uint8_t reg, uint8_t data) {
  Wire.beginTransmission(MPU6050_ADDR);
  Wire.write(reg);
  Wire.write(data);
  Wire.endTransmission();
}

int16_t read16(uint8_t reg) {
  Wire.beginTransmission(MPU6050_ADDR);
  Wire.write(reg);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU6050_ADDR, 2, true);
  int16_t val = (Wire.read() << 8) | Wire.read();
  return val;
}

void readAccel(float &ax, float &ay, float &az) {
  ax = read16(0x3B) / 16384.0; // raw / sensitivity
  ay = read16(0x3D) / 16384.0;
  az = read16(0x3F) / 16384.0;
}

void readGyro(float &gx, float &gy, float &gz) {
  gx = read16(0x43) / 131.0;
  gy = read16(0x45) / 131.0;
  gz = read16(0x47) / 131.0;
}

// -------------------- Helper Functions --------------------
void setLED(uint32_t color, const char* status) {
  strip.setPixelColor(0, color);
  strip.show();
  Serial.print("LED set to: ");
  Serial.println(status);
}

void buzzerPulse(int durationMs) {
  Serial.println("Buzzer pulse...");
  digitalWrite(BUZZER_PIN, HIGH);
  delay(durationMs);
  digitalWrite(BUZZER_PIN, LOW);
  delay(durationMs);
}

void buzzerContinuous(bool on) {
  digitalWrite(BUZZER_PIN, on ? HIGH : LOW);
  Serial.print("Buzzer continuous: ");
  Serial.println(on ? "ON" : "OFF");
}

float readAccelerationMagnitude() {
  float ax, ay, az;
  readAccel(ax, ay, az);
  float A = sqrt(ax*ax + ay*ay + az*az);
  Serial.print("Acceleration Magnitude: ");
  Serial.println(A);
  return A;
}

float readRoll() {
  float ax, ay, az;
  readAccel(ax, ay, az);
  float roll = atan2(ay, az) * 57.3;
  Serial.print("Roll: ");
  Serial.println(roll);
  return roll;
}

float readPitch() {
  float ax, ay, az;
  readAccel(ax, ay, az);
  float pitch = atan2(-ax, sqrt(ay*ay + az*az)) * 57.3;
  Serial.print("Pitch: ");
  Serial.println(pitch);
  return pitch;
}

bool checkGSM() {
  sim800.println("AT");
  delay(500);
  if (sim800.available()) {
    String resp = sim800.readString();
    Serial.print("GSM Response: ");
    Serial.println(resp);
    return resp.indexOf("OK") != -1;
  }
  return false;
}

void sendSMS(float lat, float lon) {
  if (!checkGSM()) {
    Serial.println("GSM not responding. SMS aborted.");
    return;
  }
  Serial.println("Preparing SMS...");
  sim800.println("AT+CMGF=1"); // Text mode
  delay(500);
  sim800.print("AT+CMGS=\"");
  sim800.print(PHONE_NUMBER);
  sim800.println("\"");
  delay(500);
  sim800.print("🚨 EMERGENCY ALERT 🚨\n");
  sim800.print("Possible Bike Accident\n\nLocation:\n");
  sim800.print("https://maps.google.com/?q=");
  sim800.print(lat, 6);
  sim800.print(",");
  sim800.print(lon, 6);
  sim800.println("\nPlease reach the rider immediately.");
  delay(500);
  sim800.write(26); // CTRL+Z to send
  Serial.println("SMS Sent!");
}

// -------------------- Setup --------------------
void setup() {
  Serial.begin(115200);
  Wire.begin(21,22); // SDA=21, SCL=22

  // Wake up MPU6050
  mpuWrite(0x6B, 0);

  strip.begin();
  strip.show();
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  gpsSerial.begin(9600, SERIAL_8N1, GPS_RX, GPS_TX);
  sim800.begin(9600, SERIAL_8N1, SIM800_RX, SIM800_TX);

  setLED(strip.Color(0, 0, 255), "Blue (Init)");
  Serial.println("System Initialized. Monitoring...");
  currentState = STATE_MONITORING;
}

// -------------------- Main Loop --------------------
void loop() {
  // GPS feed
  while (gpsSerial.available()) {
    gps.encode(gpsSerial.read());
    if (gps.location.isValid()) {
      lastLat = gps.location.lat();
      lastLon = gps.location.lng();
      Serial.print("GPS Fix: Lat=");
      Serial.print(lastLat, 6);
      Serial.print(" Lon=");
      Serial.println(lastLon, 6);
    }
  }

  switch (currentState) {
    case STATE_MONITORING: {
      Serial.println("STATE: MONITORING");
      setLED(strip.Color(0, 255, 0), "Green (Monitoring)");
      float A = readAccelerationMagnitude();
      if (A > IMPACT_THRESHOLD) {
        Serial.println("Impact detected!");
        currentState = STATE_IMPACT;
      }
      break;
    }

    case STATE_IMPACT: {
      Serial.println("STATE: IMPACT");
      float roll = readRoll();
      float pitch = readPitch();
      if (abs(roll) > TILT_THRESHOLD || abs(pitch) > TILT_THRESHOLD) {
        Serial.println("Tilt detected. Moving to VERIFY_TILT.");
        stateStartTime = millis();
        currentState = STATE_VERIFY_TILT;
      } else {
        Serial.println("No tilt. Returning to monitoring.");
        currentState = STATE_MONITORING;
      }
      break;
    }

    case STATE_VERIFY_TILT: {
      Serial.println("STATE: VERIFY_TILT");
      if (millis() - stateStartTime >= 3000) {
        float roll = readRoll();
        float pitch = readPitch();
        float acc = readAccelerationMagnitude();
        if ((abs(roll) > TILT_THRESHOLD || abs(pitch) > TILT_THRESHOLD) && (acc < 1.3)) {
          Serial.println("Still tilted and stable. Proceeding...");
          currentState = STATE_VERIFY_STILLNESS;
        } else {
          Serial.println("Not stable. Returning to monitoring.");
          currentState = STATE_MONITORING;
        }
      }
      break;
    }

    case STATE_VERIFY_STILLNESS: {
      Serial.println("STATE: VERIFY_STILLNESS → Starting countdown");
      stateStartTime = millis();
      currentState = STATE_COUNTDOWN;
      break;
    }

    case STATE_COUNTDOWN: {
      Serial.println("STATE: COUNTDOWN (10s). Press button to cancel.");
      setLED(strip.Color(255, 255, 0), "Yellow (Countdown)");
      if (millis() - stateStartTime < 10000) {
        buzzerPulse(250); // 0.25s ON + 0.25s OFF = 0.5s cycle
        if (digitalRead(BUTTON_PIN) == LOW) {
          Serial.println("Alert cancelled by button press.");
          currentState = STATE_MONITORING;
        }
      } else {
        Serial.println("Countdown finished. Sending SMS...");
        currentState = STATE_SEND_SMS;
      }
      break;
    }

    case STATE_SEND_SMS: {
      Serial.println("STATE: SEND_SMS");
      if (lastLat != 0.0 && lastLon != 0.0) {
        sendSMS(lastLat, lastLon);
        setLED(strip.Color(255, 0, 0), "Red (Accident Alert)");
        buzzerContinuous(true);
        currentState = STATE_WAIT_RESET;
      } else {
        Serial.println("No valid GPS fix. SMS aborted.");
        currentState = STATE_MONITORING;
      }
      break;
    }

    case STATE_WAIT_RESET: {
      Serial.println("STATE: WAIT_RESET (press button to reset)");
      if (digitalRead(BUTTON_PIN) == LOW) {
        Serial.println("System reset. Returning to monitoring.");
        buzzerContinuous;
      }
    }
  }
}
