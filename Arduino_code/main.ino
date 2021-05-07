#include <Wire.h>

#define I2C_SLAVE_ADDRESS 11

int right_forward_pin = 7;
int left_forward_pin = 8;
int right_backward_pin = 4;
int left_backward_pin = 12;

int right_forward_pwm = 0;
int left_forward_pwm = 0;
int right_backward_pwm = 0;
int left_backward_pwm = 0;

int pwm_values[5] = {0, 0, 0, 0, 0};

void receiveEvents(int numBytes){  
  Serial.println(F("---> recieved events"));
  int counter = 0;
  while (Wire.available()){
    int c = Wire.read();
    pwm_values[counter] = c;
    counter++;
  }
  right_forward_pwm = pwm_values[1];
  left_forward_pwm = pwm_values[2];
  right_backward_pwm = pwm_values[3];
  left_backward_pwm = pwm_values[4];
  Serial.println(right_forward_pwm);
  Serial.println(left_forward_pwm);
  Serial.println(right_backward_pwm );
  Serial.println(left_backward_pwm);
}

void move(){
  analogWrite(right_forward_pin, right_forward_pwm);
  analogWrite(left_forward_pin, left_forward_pwm);
  analogWrite(right_backward_pin, right_backward_pwm);
  analogWrite(left_backward_pin, left_backward_pwm);
}

void setup(){
  Serial.println("Initialising the motors!!!");
  pinMode(5, OUTPUT);
  pinMode(right_backward_pin, OUTPUT);
  pinMode(right_forward_pin, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(left_backward_pin, OUTPUT);
  pinMode(left_forward_pin, OUTPUT);

  Wire.begin(I2C_SLAVE_ADDRESS);
  Serial.begin(9600); 
  Serial.println("Start Reading");
  delay(1000);               
  Wire.onReceive(receiveEvents);
}

void loop(){
  move();
  delay(100);
}
