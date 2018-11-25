#include <Ultrasonic.h>
#include <Arduino.h>


Ultrasonic::Ultrasonic(int trigger_pin, int echo_pin){
  trig = trigger_pin;
  echo = echo_pin;
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}

//returns distance to object
int Ultrasonic::get_range(){
  long duration;
  int dist;
  digitalWrite(trig, LOW);  //sets trigger to low just to be safe
  delayMicroseconds(2);

  //sets trigger pin to high waits 10 microseconds and shuts it off
  //this creates a pulse whis is then recieved by the echo pin
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  //measures how long it takes for the pulse to arrive at the echo
  duration = pulseIn(echo, HIGH);

  //speed of sound is 340m/s whis is 0.034cm/microsecods
  //using the basic physical ecuation s = v * t with v = 0.034 and t = duration of the pulse
  //we have to divide by two because the soundwave travels double
  //the distance (from the sensor to the object and back)
  dist = duration * 0.034 / 2;
  
  return dist;
}
