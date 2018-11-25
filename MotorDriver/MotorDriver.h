#ifndef MOTORDRIVER_H
#define MOTORDRIVER_H


class MotorDriver{
  private:
    int m_left_1;
    int m_left_2;
    int m_right_1;
    int m_right_2;

  public:
    MotorDriver(int left_1, int left_2, int right_1, int right_2);
    void cleanup();
    void backward(int speed, int dur = 0);
    void forward(int speed, int dur = 0);
    void rotate_right(int speed, int dur = 0);
    void rotate_left(int speed, int dur = 0);
};


#endif
