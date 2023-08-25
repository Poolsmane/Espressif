#include <Arduino.h>
static const int led_pin=16;
//declare the pin number at which the led is present in your board
int ledPinState=1;
char c[1];
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
     c[0]=Serial.read();
     //int a=atoi(c);
      //int b=c[0]-'0';
    if(c[0]=='a'||c[0]=='A'||c[0]==49)
    { int b=1;
    while(b<50){
      digitalWrite(led_pin,LOW);
       delay(200);
      digitalWrite(led_pin,HIGH);
  Serial.println("LED is ON");
  delay(200);
  delay(1000);
   digitalWrite(led_pin,LOW);
       delay(500);
  b++;


    }
  
   /* }
   else if(c[0]=='b'||c[0]=='B'||c[0]==50)
    {
  digitalWrite(led_pin,HIGH);
  Serial.println("LED is OFF");
  delay(2000);
    }
    else
    {
      Serial.println("INVALID INPUT");
    }*/
  }

}
}
