#include <dht11.h>
#define DHT11PIN 8
float sensorValue;  
dht11 DHT11;
int led = 13;

void setup()
{

  Serial.begin(9600);  // initialize serial communications at 9600 bps
  pinMode(led,OUTPUT);
}


void loop()
{
  // serial read section
  while (Serial.available()) 
  {
    delay(30);  //delay to allow buffer to fill 
    if (Serial.available() >0)
    {
      char c = Serial.read();  //gets one byte from serial buffer
      //Serial.print( c);
      if (c == 'h' ){
        digitalWrite(led,HIGH);}
      if (c == 'l' ){
        digitalWrite(led,LOW);}
      if (c == 't'){
          int chk = DHT11.read(DHT11PIN);
          float sensorValue = ((float)DHT11.temperature);
          Serial.println(sensorValue);
          delay(100);}     
    }
  }
  
}
