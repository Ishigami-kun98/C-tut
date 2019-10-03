#include <iostream>  //linguaggio web si vive su iostream e so che non è nostro
//std::cout
using namespace std;

struct FabioNonvieneMai{
  int Fasciamassima;
  bool FasciaPezzente;
  int Fasciaminima;
};



int main() {

  std :: cout << "Davide Puzza" <<
   std :: endl;

  std::cout << "HelloWorld" <<
   std ::endl;

   std :: cout <<"Fabio non viene"
   << std ::endl;

  int value = 0;

  //once i setup namespace std
  cin >> value;

  cout << "valore di value :" <<

  value << endl;

  if (cin.fail())
    cout
    << "errore ma fabio non viene"
    <<endl;
  else
    cout <<
    "funziona ma davide se ne va"
    <<endl;

    cout << sizeof(int) << endl;

    FabioNonvieneMai davideseneva;
    davideseneva.FasciaPezzente = true;

    if (davideseneva.FasciaPezzente)
    cout <<
    "Davide è fascia Pezzente" <<endl;

    return 0;
}


void funct (float f){

}
