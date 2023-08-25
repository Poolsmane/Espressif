#include <Arduino.h>

 int led_pin1=3;
 int led_pin2=5;
static int led_state1=1;
static int led_state2=1;
//state of the led.Since state is used so it is known as state machine
static unsigned long on_time1=400;
static unsigned long off_time1=900;
static unsigned long last_update1=0;
static unsigned long last_update2=0;
static unsigned long on_time2=800;
static unsigned long off_time2=2500;

void setup()
{
  Serial.begin(115200);
  while(!Serial);
  pinMode(led_pin1,OUTPUT);
  pinMode(led_pin2,OUTPUT);
}

void loop()
{
  if(((millis()-last_update1)>on_time1)&&(led_state1==0))//check whether led is on and it is more than 400ms, led state is on as in 8266 it is reverse
  {
    last_update1=millis();//note the time so that we know what to do
    led_state1=!led_state1;//switch off the led. written 1 coz in 8266 it is reverse
    digitalWrite(led_pin1,led_state1);
    Serial.println("LED is OFF");
  }
  else if((millis()-last_update1)>off_time1 && led_state1==1) //check whether the led is still off then on it, state=1, means led is OFF
  {
     last_update1=millis();//note the time so that we know what to do
    led_state1=!led_state1;//switch on the led. written 1 coz in 8266 it is reverse
    digitalWrite(led_pin1,led_state1);
    Serial.println("LED is ON");
  }
  if(((millis()-last_update2)>on_time2)&&(led_state2==0))//check whether led is on and it is more than 400ms, led state is on as in 8266 it is reverse
  {
    last_update2=millis();//note the time so that we know what to do
    led_state2=!led_state2;//switch off the led. written 1 coz in 8266 it is reverse
    digitalWrite(led_pin2,led_state2);
    Serial.println("LED is OFF");
  }
  else if((millis()-last_update2)>off_time2 && led_state2==1) //check whether the led is still off then on it, state=1, means led is OFF
  {
     last_update2=millis();//note the time so that we know what to do
    led_state2=!led_state2;//switch on the led. written 1 coz in 8266 it is reverse
    digitalWrite(led_pin2,led_state2);
    Serial.println("LED is ON");
  }
}