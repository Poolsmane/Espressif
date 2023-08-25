#include <Arduino.h>
static const int led_pin=16;
static const int but_pin=0;
int count=0;
// put function declarations here:


void setup() {
  Serial.begin(115200);
  while(!Serial);
  pinMode(led_pin,OUTPUT);
  pinMode(but_pin,INPUT_PULLUP);
  // put your setup code here, to run once:
  
}

void loop() {
  int but_val=digitalRead(but_pin);
  if(but_val==0)
  {
    while(digitalRead(but_pin)==0)
    {
      delay(10);
    }
    count++;
    digitalWrite(led_pin,LOW);
    Serial.print("Button Pressed");
    Serial.println(count);

  }
  digitalWrite(led_pin,HIGH);
  // put your main code here, to run repeatedly:
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}