#include <iostream>

class Base{
  public:
    Base(){
      std::cout<<"Base::Base" << std::endl;
    }

    explicit Base(int){
      std::cout <<"Base::Base(int)" << std::endl;
    }

    Base(const Base &Other){
      std::cout <<"Base::Base(Base)" << std::endl;
    }

    Base &operator=(const Base &other){
      std::ciyt << "Base :: operator=" << std::endl;
    }

    ~Base(){
      std::cout << "Base:: destroyer" << std::endl;
    }
};

class voce_duplicata_exception{

}

//Everything private or public in the father class
//remain what they are
class Derived : public Base{
  Derived() : Base(7){
    std::cout << "Derived::Derived" << std::endl;
  }

  Derived(const Derived &Other) : Base(Other){
    std::cout << "Derived :: Derived()" << std::endl;
  }


  ~Derived(){
    std::cout << "Derived:: destroyer" << std::endl;
  }
}

//se class p : private Base{} everything is private

int main(int argc, char *argv[]) {
  //viene chiamato il costruttore default di derived
  //che chiama quello del padre, che chiama quello
  //del suo padre etc..............................
  Derived d;
  return 0;
}
