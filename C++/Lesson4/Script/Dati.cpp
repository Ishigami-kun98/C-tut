#include <iostream>


//dati dinamici
//int * pippo = new int;
//Allocazione dati dinamici new int
//per aganciarci a questo indirizzo usiamo i puntatori
//i dati dinamici ci costringono a usare i puntatori.
//ricordarsi di distruggerlo
//delete pippo; //delete[] pippo per un array
void funct(){
  //dati locali
  int i;
  float f;
  //Quando la funct termina vengono eliminate
}

int main(int argc, char *argv[]) {
  //i è usato locale ma ha un ciclo di vita globale cioè non muore alla fine del main
  //static int i;

  int * pippo = new int[10];
  pippo += 100;
  *pippo[100] = 0;
  delete[] pippo;
  pippo = nullptr;
  //Avviene sempre una memory leak perchè sto tentando di eliminare 100
  //elementi da un array che ha solo i primi 10 elementi e l'ultimo elemento
  //al 100 posizione, viene registrata come me

  return 0;
}
