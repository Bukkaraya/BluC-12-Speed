// Adafruit Motor shield library
// copyright Adafruit Industries LLC, 2009
// this code is public domain, enjoy!

#include <AFMotor.h>

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Motor test!");

  // turn on motor
  motor1.setSpeed(200);
  motor1.run(RELEASE);

  motor2.setSpeed(200);
  motor2.run(RELEASE);
  
  motor3.setSpeed(200);
  motor3.run(RELEASE);

  motor4.setSpeed(200);
  motor4.run(RELEASE);

}

void car_move_forward()
{
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD); 
  motor4.run(FORWARD);


}

void car_move_backward()
{
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD); 
  motor4.run(BACKWARD);
}

void left_turn() 
{ 
  motor1.run(RELEASE);
  motor3.run(RELEASE);
  motor2.run(FORWARD);
  motor4.run(FORWARD);
}

void right_turn() 
{ 
  motor1.run(FORWARD);
  motor3.run(FORWARD);
  motor2.run(RELEASE);
  motor4.run(RELEASE);
}

void loop() {
  car_move_forward();
  delay(3000);
  
  left_turn();
  delay(1500);
  
  car_move_backward();
  delay(3000);
  
  right_turn();
  delay(1500);
}
