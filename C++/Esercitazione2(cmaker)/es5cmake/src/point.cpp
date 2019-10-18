#include "point.h"
#include <iostream>

point move(point p, int dx, int dy){
  p.x += dx;
  //Se è by references allora è così p -> x
  p.y += dy;
}
