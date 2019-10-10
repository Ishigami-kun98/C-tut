#include <iostream>

//using namespace std; non lo uso piu per spiegare meglio cosa sta andando

int main(int argc, char *argv[]) {

/*for (size_t i = 0; i < argc; i++) {
    std ::cout << argv[i] << std ::endl;
  }*/

/////////////////////Args//////////////////////////
  /*Usare un puntatore per contare i caratteri
  if(argc < 2){
    //Usiamo il cerr per raccogliere il messaggio di errore e spedirlo sulla console
    //La differenza tra cerr e cout e che cerr spedisci instantaniamente
    //Cout invece puo avere un ritardo, anche se non si nota ora.
    std :: cerr << "Lack an Fabioment(Argument)" << std :: endl;
    return 0; // senza questa return non finisce qui la storia
  }
  char *start = argv[1];
  char *end = 0;

  end = start;

  //Carattere di fine stringa = '\0'
  while (*end != '\0') {
    end = end +1;
  }

  int size = end -start;

  std :: cout << "size di argv[1] : " << size << std ::endl;
  */

///////////////////////Cast tipo ////////////////////////

  /*cast tra tipi di dati
  int sx = 1000;
  char dx = 9;
  sx = dx; //Cast implicito

  //Cast esplicito
  dx = static_cast<char>(sx);

  const int *pci = 0; //Dati costanti

  //Gli stiamo dicendo che vogliamo manipolare dati protetti
  int *pi = const_cast<int *>(pci);

  char *pc = 0;
  //Cambio il puntatore di char in int esplicitamente
  int * dst = reinterpret_cast<int *>(pc);
  */

  

  return 0;
}
