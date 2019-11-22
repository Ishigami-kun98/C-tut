#include <iostream>
#include <algorithm>

class functor {
  double inner;
public:
  functor(double d) : inner(d) {}
  double operator()(double v) const {
  return v*inner;
  }
};

int main(int argc, char *argv[]) {
  double array[5] = {1.0,2.0,3.0,4.0,5.0};

  std::transform(array,array+5,array,functor(3)); // array={3.0,6.0,9.0,12.0,15.0}
  /*
  double inner = 3;
  //lambda
  std::transform(array,array+5,array,[=](double d){return d*inner;};
*/
//oppure
double inner = 3;
auto lambda = [=](double d){return d*inner;};
std::transform(array,array+5,array,lambda);
  for (size_t i = 0; i < 5; i++) {
    std::cout << array[i] << std::endl;
  }

  return 0;
}
