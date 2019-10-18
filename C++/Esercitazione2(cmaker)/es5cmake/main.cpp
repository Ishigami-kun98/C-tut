#include <iostream>
#include "point.h"
#include "rectangle.h"

int main(){
  int x, y;
  std:: cout <<"Inserisci x e y tr" ;
  std :: cin >> x >> y;

  point tr;
  tr.x = x;
  tr.y = y;

  std :: cout << "insert x and y value for bl" ;
  std :: cin >> x >> y;

  point bl;
  bl.x = x;
  bl.y = y;

  rectangle r;
  r.bl = bl;
  r.tr = tr;

  std :: cout << "\n rectangle area is " << area(r) << std::endl;
  return 0;
}
