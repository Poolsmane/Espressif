#include <Arduino.h>
static const int led_pin=16;
static int led_state=0;
//state of the led.Since state is used so it is known as state machine
static unsigned long on_time=400;
static unsigned long off_time=900;
static unsigned long last_update=0;

void setup()
{
  Serial.begin(115200);
  while(!Serial);
  pinMode(led_pin,OUTPUT);
}

void loop()
{
  if(((millis()-last_update)>on_time)&&(led_state==0))//check whether led is on and it is more than 400ms, led state is on as in 8266 it is reverse
  {
    last_update=millis();//note the time so that we know what to do
    led_state = 1;       // switch off the led. written 1 coz in 8266 it is reverse
    digitalWrite(led_pin,led_state);
    Serial.println("LED is OFF");
  }
  else if((millis()-last_update)>off_time && led_state==1) //check whether the led is still off then on it, state=1, means led is OFF
  {
     last_update=millis();//note the time so that we know what to do
    led_state=0;//switch on the led. written 1 coz in 8266 it is reverse
    digitalWrite(led_pin,led_state);
    Serial.println("LED is ON");
  }
}