#include <iostream>
#include <cassert>
#include <string>

using namespace std;
class Forma{
private:
  string id;
  int colore;
  bool pieno;
public:
  //Crepato per colpa del terzo Forma
  //explicit Forma(const std::string &_id) :
  //id(_id), colore(0), pieno(false){
  //}

  Forma(Forma &Other) :
   id(Other.id), colore(Other.colore),
    pieno(Other.pieno){

  }
//Avendo questo, il primo puo gia crepare
  Forma(const std::string &_id,
    int _colore = 0, bool _pieno = false) :
    id(_id), colore(_colore),
    pieno(_pieno){

  }

  Forma & operator=(const Forma & other)
  {
    if(this != &other){
      id = other.id;
      colore = other.colore;
      pieno = other.pieno;
    }
    return *this;
  }

  ~Forma(){
    //No heap allocation so everything
    // will die well themself
  }

  const std::string &id() const {
    return id;
  }

  const int &colore() const {
    return colore;
  }

  const bool &pieno() const{
    return pieno;
  }

  void set_colore(int _colore){
    colore = _colore;
  }

  void set_pieno(bool _pieno){
    pieno = _pieno;
  }

  virtual double get_perimetro() const = 0;
  //Metodo virtuale, cioè definito ma non
  //Esiste realmente, cioè virtuale.
  //Dichiarando questo, non potremo mai piu
  //Istanziare la classe forma.
  //Questa classe adesso è un connettore di
  //Informazioni comuni, ma non ha senso di
  //esistere da sola.
  //Inoltre tutte le sue classi derivate sono
  //POLIMORFE
};

class Punto: public Forma{
private:
  double x;
  double y;

public:
  Punto() : x(0), y(0){}
  Punto(double xx, double yy) : x(xx), y(yy){}
};

class Cerchio : public Forma{
  Punto centro;
  double raggio;
public:
  Cerchio(const Punto &c, double r) :
  Forma(id),
   centro(c), raggio(0){
    assert(r > 0);
    raggio = r;
  }
  Cerchio(const Cerchio &other) :
  Forma(other), centro(other.centro){}
  Cerchio & operator=(const Cerchio &other){
    if(this != other){
      Forma ::operator=(other);
      centro = other.centro;
      raggio = other.raggio;
    }
    return *this;
  }

  ~Cerchio(){}

  const Punto &centro() const{
    return centro;
  }

  void set_centro(const Punto &p) {
    centro = p;
  }

  double raggio() const{
    return raggio;
  }

  void set_raggio(double r){
    raggio = r;
  }

  const double get_perimetro() const{
    return 2*3.14*raggio;
  }

};

int main(int argc, char *argv[]) {
  //Con virtual nella classe non posso piu:
  //Forma f; mi da errore.
  Cerchio c1("C1", Punto(), 10);
  return 0;
}
