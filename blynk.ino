/*************************************************
 * ESP32 + Blynk IoT + Relay 16 Channel
 * LOW Level Trigger Relay
 * Button (Switch) V0 - V15
 *************************************************/

// ===== BLYNK =====
#define BLYNK_TEMPLATE_ID "TMPL6q6NLFsz6"
#define BLYNK_TEMPLATE_NAME "Relay16Module"
#define BLYNK_AUTH_TOKEN    "OCh_HUukYqrqk2QAqAbkLcgX64iPSdjx"

#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

// ===== WIFI =====
char ssid[] = "iPhone";
char pass[] = "12345678";

// ===== RELAY LOGIC =====
#define RELAY_ON  LOW
#define RELAY_OFF HIGH

// ===== RELAY PIN MAP =====
int relayPin[16] = {
  16, 17, 18, 19,   // CH1 - CH4
  21, 22, 23,       // CH5 - CH7
  25, 4, 13,        // CH8 - CH10
  14, 33,           // CH11 - CH12
  32, 27,           // CH13 - CH14
  26, 5             // CH15 - CH16
};

// ===== FUNCTION =====
void controlRelay(int ch, int value) {
  digitalWrite(relayPin[ch], value ? RELAY_ON : RELAY_OFF);

  Serial.print("Relay ");
  Serial.print(ch + 1);
  Serial.println(value ? " ON" : " OFF");
}

// ===== SETUP =====
void setup() {
  Serial.begin(115200);
  delay(500);

  Serial.println("ESP32 Relay 16CH with Blynk");

  // Init relay pins
  for (int i = 0; i < 16; i++) {
    pinMode(relayPin[i], OUTPUT);
    digitalWrite(relayPin[i], RELAY_OFF);
  }

  // Connect Blynk
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  Serial.println("Blynk Ready");
}

// ===== LOOP =====
void loop() {
  Blynk.run();
}

// ===== BLYNK CONTROL =====
BLYNK_WRITE(V0)  { controlRelay(0,  param.asInt()); }
BLYNK_WRITE(V1)  { controlRelay(1,  param.asInt()); }
BLYNK_WRITE(V2)  { controlRelay(2,  param.asInt()); }
BLYNK_WRITE(V3)  { controlRelay(3,  param.asInt()); }
BLYNK_WRITE(V4)  { controlRelay(4,  param.asInt()); }
BLYNK_WRITE(V5)  { controlRelay(5,  param.asInt()); }
BLYNK_WRITE(V6)  { controlRelay(6,  param.asInt()); }
BLYNK_WRITE(V7)  { controlRelay(7,  param.asInt()); }
BLYNK_WRITE(V8)  { controlRelay(8,  param.asInt()); }
BLYNK_WRITE(V9)  { controlRelay(9,  param.asInt()); }
BLYNK_WRITE(V10) { controlRelay(10, param.asInt()); }
BLYNK_WRITE(V11) { controlRelay(11, param.asInt()); }
BLYNK_WRITE(V12) { controlRelay(12, param.asInt()); }
BLYNK_WRITE(V13) { controlRelay(13, param.asInt()); }
BLYNK_WRITE(V14) { controlRelay(14, param.asInt()); }
BLYNK_WRITE(V15) { controlRelay(15, param.asInt()); }