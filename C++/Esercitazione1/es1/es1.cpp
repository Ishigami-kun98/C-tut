//Calcolare l'integrale di una funzione f(x)
//usando la tecnica di approssimazione dei trapezi

#include <iostream>
#include <cmath>
using namespace std;

float f(float x){
    return sin(x);
}

float fi(float x){
  return cos(x);
}

int main(){

  //Dalla formula(Cercalo su internet) ci servono 2 variabili float o double
  float a = 0;
  //Pigreco = M_PI
  float b = M_PI;

  //Per avere un input
  int N;

  //Chiedere all'utente l'input
  cout << "inserire un numero" <<endl;
  //Inserire con tastiera il valore e assegnarlo a N;
  cin >> N;

  //Dobbiamo necessariamente porre il numero di variabile di tipo floating
  float D = (b - a) / N; //b-a ci da la lunghezza di tutto l'intervallo
  //Stiamo stimando il valore della deltaX per tutto l intervallo.

  //A sto punto abbiamo tutti i elementi per implementare sta funzione.

  //Usato per sommare i valori dei singoli intervalli

  float integrale = 0;

//ciclo for per il problema
  for (int k = 1; k < N; k++) {
    //Come si vede è la traduzione della formula in codice
    integrale += (((f(a+(k-1) * D)) + f(a + k * D)))/2;
  }

//last touch
  integrale *= D;

//stampa result
  cout << "Abbiamo finito e il risultato e: " << integrale <<endl;

  return 0;

}
