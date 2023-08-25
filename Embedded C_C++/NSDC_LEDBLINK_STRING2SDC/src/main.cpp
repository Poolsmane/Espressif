#include <Arduino.h>
static const int led_pin=16;
static const int but_pin=0;
int count=0;
 void setup()
 {
  Serial.begin(115200);
  while(!Serial);
  pinMode(led_pin,OUTPUT);
  pinMode(but_pin,INPUT_PULLUP);
 }
 void loop()
 {
  int but_value=digitalRead(but_pin);
  if(but_value==0)
  {
    while(digitalRead(but_pin)==0)
    {
      delay(10);
    }
    count++;
    digitalWrite(led_pin,LOW);
    Serial.println("Button Pressed");
    Serial.println(count);
  }
  
    digitalWrite(led_pin,HIGH);
  
 }