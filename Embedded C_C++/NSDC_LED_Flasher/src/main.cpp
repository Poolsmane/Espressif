#include <Arduino.h>
class Flasher //embedded c++
{
 int led_pin;
 int led_state;
 unsigned long on_time;
 unsigned long off_time;
 unsigned long last_update;
 //defining constructor for the creation of the object
 public: //by defalut private in c
 Flasher(int pin, unsigned long ont, unsigned long oft)
 {
  led_pin=pin;//led pin
  led_state=HIGH;//pin state, LOW in case of esp32
  on_time=ont;//led on time(ms)
  off_time=oft;//led off time(ms)
  pinMode(led_pin,OUTPUT);//pin mode
  last_update=0;//time when the led state was updated in last time
 }
 void update()
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

 };
};
 Flasher led1(16,400,800);
 Flasher led2(2,2000,1500);
 void setup()
 {
  Serial.begin(115200);
  while(!Serial);
  Serial.println("--LED Flasher Class--");

 }
 void loop()
 {
  led1.update();//update the state of led1;
  led1.update();//update the state of led2;
 }


