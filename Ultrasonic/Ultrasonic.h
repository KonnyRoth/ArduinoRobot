#ifndef ULTRASONIC_H
#define ULTRASONIC_H

/*
This lib is created for the HC-SR04 ultrasonic sensor
*/
class Ultrasonic{
  private:
    long duration;
    int dist;
    int trig;
    int echo;

  public:
    Ultrasonic(int trigger_pin/*trigger*/, int echo_pin /*echo*/);
    int get_range();
};



#endif
