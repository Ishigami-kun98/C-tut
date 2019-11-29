#ifndef OLIST_H
#define OLIST_H

//le risorse da distruggere sono stringhe di output, new, e allocazioni di memoria

//C(a,b) deve ritornare true sse a<b
  template <typename T, typename C>
//classe deve rappresentare una lista
  class ordered_list{
    struct node{
      T value;
      node *next;

      node() : next(nullptr) {}
      node(const T &v, node *n) : value(v), next(n){}
      node(const T &v) : value(v) :value(v), next(nullptr){}
      ~node(){
        next = nullptr;
        //Template muoiono da soli non serve distruggerli
      }
    };

    node *head;
    unsigned int size;

  public:
    ordered_list() : head(nullptr), size(0){

    }
    ordered_list(const ordered_list &other){
      node *curr = other -> head;
        try{
        while(curr != nullptr){
          add(curr -> value);
          curr = curr -> next;
        }
      }catch(...){
        clear();
        throw;
      }
    }
    ordered_list &operator=(const ordered_list other){
      if(this != &other){
        ordered_list tmp(other);
        std::swap(head, tmp.head);
        std::swap(size, tmp.size);
      }
      return *this;
    }

    ~ordered_list(){

    }

    unsigned int size() const{
      return size;
    }

    bool find(T &value) const{

    }

    template <typename IterT>
    ordered_list(IterT begin, IterT end){

    }

  };

  template<typename T>
  std:: ostream &operator <<(std::ostream &os, const ordered_list &ol){
    return os;
  }



  void clear(){
    node *curr = head;
    node *tmp = nullptr;
    while(curr != nullptr){
      tmp = curr -> next;
      delete curr;
      curr = tmp;
    }

    //clear_helper(head);
    //head = nullptr;
    //size = 0;
  }

  //void clear_helper(){..}

  void add(const &value){
    node *tmp = new node(value);

    if(head == nullptr){
      head = tmp;
      return;
    }

    C conf;
    node *curr = head;
    node *prev = head;
    while(curr != nullptr){
      //conf serve per dire che i due valori sono in ordine
      //curr -> value è > value? se il nodo corrente contiene
      //un valore piu grande di value, deve tornare indietro
      //e viceversa
      if(conf(curr -> value, value)){
        //se il confronto è buono mi sposto ma prev
        //deve puntare a curr;
        prev = curr;
        curr = curr -> next;
      }
      else{
        if(head == curr){
          head = tmp;
          tmp -> next = curr;
      }else{
        prev -> next = tmp;
        tmp -> next = curr;
      }
        return;
      }
    }
  }

#endif
