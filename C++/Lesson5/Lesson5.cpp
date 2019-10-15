#include <iostream>

//Function passaggio di parametri alle funzioni, there is 3 way, valore, puntatore, references
//Passaggio per valore
void funct1(double d){
  //Abbiamo il dato di partenza, lo passiamo, e il dato viene copiato in questo caso nella
  //Variabile d
  d = 10;
}

void funct2(double *pd){
  pd[0] = 0.0;
}

//Chiamata di funct1
double dd = 3.14;
funct1(dd);

int main(int argc, char *argv[]) {

  int *aint = new int[100];
  int **matrix = nullptr;
  //puntatori di puntatori agli interi
  //La mia matrice è composta da array di puntatori interi
  //devo costruire un array di puntatori di interi
  matrix = new int*[10];
  //Ogni volta che facciamo una new possiamo avere un problema di no memory
  //Cosa succede se non va a buon fine?
  //Fai sempre
  for (size_t i = 0; i < 10; i++) {
    matrix[i] = nullptr;
  }
  //Un array di puntatori a(Ciasuno dei quali viene riempito nel for)
  int r;
  //Try si usa sempre perche se non ho memoria per allocare i miei dati heap non va bene
  try{
    for (size_t r = 0; r < 10; r++) {
      matrix[r] = new int[100];
    }
  }catch(....){ //Non funziona per il catch
    for (size_t i = 0; i < r; i++) {
      delete[] matrix[i];
      matrix[i] = nullptr;
    }
    delete[] matrix;
    matrix = nullptr;
  }

  matrix[2][10];

  //Per cancellare la matrix bisogna fare una delete diversa per array bidimensionale

  for (size_t r = 0; r < 10; r++) {
    delete[] matrix[r];
    matrix[r] = nullptr;
  }

  delete[] aint;
  aint = nullptr;

  return 0;
  //Abbiamo finito con i dati
}
