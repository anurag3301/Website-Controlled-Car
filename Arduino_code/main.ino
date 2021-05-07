#include <Wire.h>

#define I2C_SLAVE_ADDRESS 11

int right_forward_pin = 7;
int left_forward_pin = 8;
int right_backward_pin = 4;
int left_backward_pin = 12;

void receiveEvents(int numBytes)
{  
  Serial.println(F("---> recieved events"));
  while (Wire.available()){
    int c = Wire.read();
    Serial.println(c);
  }
}

void forward(){
  analogWrite(right_backward_pin, 255);
  analogWrite(left_backward_pin, 255);
  analogWrite(right_forward_pin, 0);
  analogWrite(left_forward_pin, 0);
}


void setup()
{
  Serial.println("Initialising the motors!!!");
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(8, OUTPUT);

  Wire.begin(I2C_SLAVE_ADDRESS);
  Serial.begin(9600); 
  Serial.println("Start Reading");
  delay(1000);               
  Wire.onReceive(receiveEvents);
}

void loop(){
  forward();
}


