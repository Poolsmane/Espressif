#include <Arduino.h>
static const int led_pin=16;
//declare the pin number at which the led is present in your board
int ledPinState=1;
void setup()
{
  //pin configuration
  pinMode(led_pin,OUTPUT);
  //Serial configuration
  Serial.begin(9600);
  while(!Serial);
  Serial.println("--LED BLINKING");
}
void loop()
{
  if(Serial.available())
  {
    char c=Serial.read();
    if(c=='a'||c=='A')
    {
  digitalWrite(led_pin,LOW);
  Serial.println("LED is ON");
  delay(2000);
    }
    if(c=='b'||c=='B')
    {
  digitalWrite(led_pin,HIGH);
  Serial.println("LED is OFF");
  delay(1000);
    }
    else
    {
      Serial.println("INVALID INPUT");
    }
  }

}
