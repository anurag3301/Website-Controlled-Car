#include <Wire.h>

#define I2C_SLAVE_ADDRESS 11

int led_pin = 19;
int led_state = LOW;

// make sure all the below pin below should be PWM enabled
int right_forward_pin = 7;
int left_forward_pin = 8;
int right_backward_pin = 4;
int left_backward_pin = 12;

int right_forward_pwm = 0;
int left_forward_pwm = 0;
int right_backward_pwm = 0;
int left_backward_pwm = 0;

int pwm_values[6] = {0, 0, 0, 0, 0, 0};

// This function is called when ever there is I2C receive call
void receiveEvents(int numBytes){  
  Serial.println("----GOT " + String(numBytes) + " Bytes-----");
  int counter = 0;
  while (Wire.available()){
    int pwm = Wire.read();
    pwm_values[counter] = pwm;
    counter++;
  }
  //Update the global pwm variable
  right_forward_pwm = pwm_values[1];
  left_forward_pwm = pwm_values[2];
  right_backward_pwm = pwm_values[3];
  left_backward_pwm = pwm_values[4];
  led_state = pwm_values[5];
  // Print out the updated pwm values
  Serial.println(right_forward_pwm);
  Serial.println(left_forward_pwm);
  Serial.println(right_backward_pwm );
  Serial.println(left_backward_pwm);
  Serial.println(led_state);
} 

// This function sends the pwm signal to motor driver to rotate the motors
void move(){
  analogWrite(right_forward_pin, right_forward_pwm);
  analogWrite(left_forward_pin, left_forward_pwm);
  analogWrite(right_backward_pin, right_backward_pwm);
  analogWrite(left_backward_pin, left_backward_pwm);
  digitalWrite(led_pin, led_state);
}

void setup(){
  Serial.println("Initialising the motors!!!");
  pinMode(5, OUTPUT);   // Enable pin 1 of motor driver
  pinMode(right_backward_pin, OUTPUT);
  pinMode(right_forward_pin, OUTPUT);
  pinMode(6, OUTPUT);   // Enable pin 2 of motor driver
  pinMode(left_backward_pin, OUTPUT);
  pinMode(left_forward_pin, OUTPUT);
  pinMode(led_pin, OUTPUT);

  Serial.begin(9600); 
  Serial.println("Start Reading");

  Wire.begin(I2C_SLAVE_ADDRESS);
  delay(1000);
  Wire.onReceive(receiveEvents);
}

void loop(){
  move();
  delay(100);
}
