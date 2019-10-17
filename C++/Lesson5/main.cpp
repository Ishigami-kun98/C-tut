#include <iostream>
#include "stringhe.h"

int main(int argc, char *argv[]) {
  if(argc < 2){
    std :: cerr << "no input string" << std::endl;
    return -1;
  }

  stampa_stringa(argv[1]);
  std :: cout << "Lunghezza Stringa : " << lunghezza_Stringa(argv[1]) << std ::endl;

  inverti_stringa(argv[1]);
  std :: cout << "Stringa invertita: "<< argv[1] << std :: endl;





  char * cloned_stringa = clona_stringa(argv[1]);

  std::cout << "Stringa clonata: " << cloned_stringa << std::endl;

  delete[] cloned_stringa;
  cloned_stringa = nullptr;

  return 0; 
}
