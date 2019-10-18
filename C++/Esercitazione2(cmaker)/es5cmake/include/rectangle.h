#ifndef _rectangle_h_
#define _rectangle_h_
#include "point.h"

  struct rectangle{
    point bl;
    point tr;
  };

  int width(rectangle r);
  int height(rectangle r);
  int area(rectangle r);

#endif
