#include "car.h"
#include <math.h>

Car::Car()
{
  x = 0, y = 0;
  rotation = 0;
}

int Car::getX()
{
  return x;
}

int Car::getY()
{
  return y;
}

int Car::getDegree()
{
  return rotation;
}

void Car::turn(int degree)
{
  rotation += degree;
  if (rotation >= 360)
    rotation -= 360;
  else if (rotation < 0)
    rotation += 360;
}

void Car::move()
{
  double radianRotation = rotation * (3.14159 / 180);
  x += cos(radianRotation);
  y += sin(radianRotation);

  // Collisions
  if (getY() + 64 > 800) // Bottom
    y = 800 - 64;
  if (getY() < 0) // Top
    y = 0;
  if (getX() + 64 > 1200) // Right
    x = 1200 - 64;
  if (getX() < 0) // Left
    x = 0;
}
