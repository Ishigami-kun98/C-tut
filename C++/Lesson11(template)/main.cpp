template <typename> //prende un tipo generico
void myswap(int &a, int &b){
  int c = a;
  a = b;
  b = c;
}


int main(int argc, char const *argv[]) {
  int a,b;
  myswap(a,b);  
  return 0;
}
