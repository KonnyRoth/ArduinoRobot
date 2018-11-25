#include "MotorDriver.h"
#include <Arduino.h>

MotorDriver::MotorDriver(int left_1, int left_2, int right_1, int right_2){
  m_left_1 = left_1;
  m_left_2 = left_2;
  m_right_1 = right_1;
  m_right_2 = right_2;

  //pin setup
  pinMode(m_left_1, OUTPUT);
  pinMode(m_left_2, OUTPUT);
  pinMode(m_right_1, OUTPUT);
  pinMode(m_right_2, OUTPUT);
}

//shuts off all motors
void MotorDriver::cleanup() {
  digitalWrite(m_left_1, LOW);
  digitalWrite(m_left_2, LOW);
  digitalWrite(m_right_1, LOW);
  digitalWrite(m_right_2, LOW);
}

//moves in given direction at given speed and stops after given amount of time
//duration is optional
void MotorDriver::backward(int speed, int dur = 0) {
  analogWrite(m_left_1, speed);
  analogWrite(m_right_1, speed);

  //shuts off motors after given duration
  if(dur != 0){
    delay(dur);
    cleanup();
  }
}

//moves in given direction at given speed and stops after given amount of time
//duration is optional
void MotorDriver::forward(int speed, int dur = 0) {
  analogWrite(m_left_2, speed);
  analogWrite(m_right_2, speed);

  //shuts off motors after given duration
  if(dur != 0){
    delay(dur);
    cleanup();
  }
}

void MotorDriver::rotate_right(int speed, int dur = 0){
  analogWrite(m_left_1, 0);
  analogWrite(m_left_2, speed);
  analogWrite(m_right_1, speed);
  analogWrite(m_right_2, 0);

  //shuts off motors after given duration
  if(dur != 0){
    delay(dur);
    cleanup();
  }
}

void MotorDriver::rotate_left(int speed, int dur = 0){
  analogWrite(m_left_1, speed);
  analogWrite(m_left_2, 0);
  analogWrite(m_right_1, 0);
  analogWrite(m_right_2, speed);

  //shuts off motors after given duration
  if(dur != 0){
    delay(dur);
    cleanup();
  }
}
