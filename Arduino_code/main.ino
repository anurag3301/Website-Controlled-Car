#include <Wire.h>

#define I2C_SLAVE_ADDRESS 11

void receiveEvents(int numBytes)
{  
  Serial.println(F("---> recieved events"));
  while (Wire.available()){
    int c = Wire.read();
    Serial.println(c);
  }
}

void setup()
{
  Wire.begin(I2C_SLAVE_ADDRESS);
  Serial.begin(9600); 
  Serial.println("Start Reading");
  delay(1000);               
  Wire.onReceive(receiveEvents);
}

void loop(){
  
}
