#include <Arduino.h>
#include <SimpleFOC.h>

// HardwareSerial Serial1(PB7, PB6);  // uart1
HardwareSerial Serial3(PB11, PB10);   // uart3
MagneticSensorI2C sensor = MagneticSensorI2C(AS5600_I2C);

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);

  Serial3.begin(115200);
  delay(500);
  Serial3.println("Starting sensor init");
  delay(500);
  
  Serial3.println("Wire setup");
  Wire = TwoWire(PB9, PA15);
  delay(500);
  
  Serial3.println("Begin");
  Wire.begin();
  delay(500);
  
  Serial3.println("setck");
  Wire.setClock(400000);  // STM arduino platform setClock assumes Wire is initialized
  sensor.init();
}

void loop() {
  
  // Blink to visibly show hangs
  digitalWrite(LED_BUILTIN, HIGH);  // PC11
  Serial3.println("High");
  
  // i2C test - monitor sensor value
  sensor.update();
  Serial3.println(sensor.getAngle());
  delay(1000);
  
  digitalWrite(LED_BUILTIN, LOW);
  Serial3.println("Low");
  delay(1000);

  // RX test - echo
  if (Serial3.available()){
    Serial3.println(Serial3.readString()); 
  }
}