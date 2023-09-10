#include <Arduino.h>

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(PB10, OUTPUT);  // set pinmodes (uart2)
  pinMode(PB11, INPUT);
  
  
  Serial.begin(115200); // uart2
}

String str;
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);  // PC11
  Serial.println("High");
  delay(5000);
  digitalWrite(LED_BUILTIN, LOW);
  Serial.println("Low");
  delay(5000);
  if (Serial.available()){
    Serial.println(Serial.readString());
  }
}