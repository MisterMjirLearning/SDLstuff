#ifndef CAR
#define CAR

class Car
{
public:
  Car();
  int getX();
  int getY();
  int getDegree();
  void turn(int);
  void move();
private:
  double x, y;
  int rotation; // Degree Rotation
};

#endif
