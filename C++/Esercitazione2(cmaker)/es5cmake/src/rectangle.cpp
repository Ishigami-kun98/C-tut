#include "rectangle.h"

int width(rectangle r){
  return r.tr.x - r.bl.x;
}

int height(rectangle r){
  return r.tr.y - r.bl.y;
}

int area(rectangle r){
  return width(r) * height(r);
}
