#include <iostream>
#include <string>

using namespace std;

int main(){
  //sbagliatissimo
  void *po;

  //Si puo fare ma è complicato
  int **pppppp;

  //Assegno a pi l'indirizzo dove contiene il valore di i;
  int i = 100;
  int *pi = &i;

  //Cambio il valore di i in 0 con *puntatore
  *pi = 0;

  //il puntatore pj assume l'indirizzo di pi
  //se facciamo pj = &pi da un errore
  int *pj = pi;

  pj = pj+1;

  cout << "pi "  << pi <<endl;
  cout << "pi +1" << pj << endl;

  int array[100]; // genera 100 elementi randomici nel range dell'int se non
  //assegnamo valori

  //int array[100] = {1, 2, 3, 4}; //array unidimensionale
  //Non si puo dichiarare due volte facendo l'overriding e da errore

  int array2d[10][20];  //array multidimensionali

  int n = pi -pj; //mi da il numero di elementi compresi tra i due

  bool ok = (pi > pj);

  bool ok2 = (*pi > *pj);

  int &ref = n;

  typedef unsigned long int uli;

  //const essendo non modificabile bisogna dargli un valore subito.
  const double pigreco = 3.14;

  const int *pc;

  pc = &i;

  //*pc = 2; mi dà errore

  //int *const pc2;

  char str[] = "aisujdiawjdiawsd \0";
  //ppstr punta al primo elemento di str.
  char *pstr = str;

  //Se puntatore punta a un char di array stampa tutta la stringa
  cout <<pstr <<std ::endl;
}
