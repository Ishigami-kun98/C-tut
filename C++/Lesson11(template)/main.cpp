#include <iostream>
#include "dbufferT.h" // dbuffer
#include <cassert>   // assert

template <typename T>
void myswap(T &a, T &b) {
	T c = a;
	a = b;
	b = c;
}

struct minimo_interi{
	bool operator()(int a, int b) const{

	}
}

template <typename T, typename P>
void stampa_se(T * a, int size , P predicato){
	for (size_t i = 0; i < size; 	i++) {
		if(predicato(a[i])){
			std::cout << a[i] << std::endl;
		}
	}
}

struct maggiore_di{
private:
	int soglia;
public:
	bool operator() (int a )const{
		return a > soglia;
	}
	maggiore_di(int s) : soglia(s){

	}
};

template <typename T>
int minimo_array(int * a, int size){
	int minimo = a[0];
	for (size_t i = 0; i < size; i++) {
		if(a[i] < minimo)
		minimo = a[i];
	}
	return minimo;
}

int main(int argc, char *argv[]) {
	assert(size > 0);

	T minimo = a[0];

	int a,b;
	dbuffer<double> d1,d2;

	myswap<int>(a,b);

	myswap(d1,d2);

	maggiore_di md(5), md2(10);

	return 0;
}
