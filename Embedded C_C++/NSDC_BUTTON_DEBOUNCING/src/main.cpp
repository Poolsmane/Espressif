#include <Arduino.h>
static const int led_pin=16;
static const int but_pin=0;
//global variables declaration
static int button_state=HIGH;
static int last_button_state=HIGH;
//since high is considered low state in the node mcu boards or esp8266 boards. This prpgram is performed on ESP32
static unsigned long last_debounce_time=0;
static unsigned long debounce_delay=50;
//debounce time is in miliseconds
void setup()
{
  Serial.begin(9600);
  while(!Serial);
  pinMode(led_pin,OUTPUT);
  pinMode(but_pin,INPUT_PULLUP);

}
void loop()
{
  int reading=digitalRead(but_pin);
  //read the button value using digital read function
  if(reading!=last_button_state)// check whether the button is pressed or not
  {
    last_debounce_time=millis();
    //Serial.println(millis());
    //to debug and find that whether millis hange or not
    //millis function is used to check the amount of time the button is pressed or we could say how much time it is pressed
    //using millis()we could find out that when next button would be pressed so that check after the debounce delay if it is pressed then it is on

  }
  if((millis()-last_debounce_time)>debounce_delay)
  {   //Serial.print(millis());
   
   //if the button is still pressed
   if(reading!=button_state)
   {     
    //Serial.println(millis());
    button_state=reading;
    if(button_state==LOW)//in esp8266 low is considered to be high
    {
      Serial.println("Button is pressed");
      

    }
   }
  }

}