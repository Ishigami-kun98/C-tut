#ifndef DBUFFERT_H
#define DBUFFERT_H
#include <ostream> // std::ostream
#include <iostream>
#include <cassert>
#include <iterator>
#include <stddef>


template <typename T>
class dbuffer {
public:
	typedef unsigned int size_type;
	typedef T value_type;

private:

	size_type _size;
	T *_buffer;

public:

	dbuffer() : _size(0), _buffer(nullptr) {
	#ifndef NDEBUG
	std::cout<<"dbuffer::dbuffer()"<<std::endl;
	#endif
	}

	explicit dbuffer(size_type sz) : _size(0), _buffer(nullptr) {

	_buffer = new T[sz];
	_size = sz;

	#ifndef NDEBUG
	std::cout<<"dbuffer::dbuffer(unsigned int)"<<std::endl;
	#endif
	}

	dbuffer(size_type sz, const T &value) : _size(0), _buffer(nullptr) {

	_buffer = new T[sz];
	_size = sz;

	try {
		for(size_type i=0; i<_size; ++i)
			_buffer[i] = value;
	}
	catch(...) {
		delete[] _buffer;
		_buffer = nullptr;
		_size = 0;
		throw;
	}

	#ifndef NDEBUG
	std::cout<<"dbuffer::dbuffer(unsigned int,int)"<<std::endl;
	#endif
	}

	dbuffer(const dbuffer &other) : _size(0), _buffer(nullptr) {

	_buffer = new T[other._size];

	try {
	for(unsigned int i = 0; i < other._size; ++i)
		_buffer[i] = other._buffer[i];
	}
	catch(...) {
		delete[] _buffer;
		_buffer = nullptr;
		_size = 0;
		throw;
	}
	_size = other._size;

	#ifndef NDEBUG
	std::cout<<"dbuffer::dbuffer(const dbuffer&)"<<std::endl;
	#endif

}

	dbuffer& operator=(const dbuffer& rhs) {
	if(this != &rhs) {

		dbuffer tmp(rhs);

		std::swap(this->_buffer, tmp._buffer);
		std::swap(this->_size, tmp._size);

	}

	#ifndef NDEBUG
	std::cout<<"dbuffer::operator=(const dbuffer&)"<<std::endl;
	#endif

	return *this;
	}


	~dbuffer()  {
	delete[] _buffer;
	_buffer = nullptr;
	_size = 0;

	#ifndef NDEBUG
	std::cout<<"dbuffer::~dbuffer()"<<std::endl;
	#endif
	}

	size_type size() const {
	return _size;
	}


	T& get_value(size_type index) const {
	assert(index<_size);

	return _buffer[index];
	}


	void set_value(size_type index, const T &value) {
	assert(index < _size);

	_buffer[index] = value;
}

	T& value(size_type index) {
	assert(index<_size);

	return _buffer[index];
	}

	const T& value(size_type index) const {
	assert(index<_size);

	return _buffer[index];
	}


	T& operator[](size_type index) {
	assert(index<_size);

	return _buffer[index];
	}


	const T& operator[](size_type index) const {
	assert(index<_size);

	return _buffer[index];
	}

	void print() const {
	std::cout<<"dimensione: " << _size << std::endl;
	for(size_type i=0; i<_size; ++i)
		std::cout << _buffer[i] << std::endl;
	}

	void swap(dbuffer &other) {

	std::swap(_buffer, other._buffer);

	std::swap(_size, other._size);
	}


template <typename U>
friend std::ostream &operator<<(std::ostream &os,const dbuffer<U> &db) {
	os << db._size << std::endl;
	for(typename dbuffer::size_type i =0;
		i < db._size; i++)
		os << db._buffer[i] << std::endl;

	return os;
}

	// Per la nostra classe possiamo sfruttare il puntatore come iterator
	// random. Per compatibilità con la libreria standard del C++,
	// dobbiamo però utilizzare i nomi standard degli iteratori.
	// Per questo motivo dobbiamo mappare i puntatori ai nomi degli iteratori
	// con typedef. In generale è necessatio ridefinire le classi degli iteratori.

	// Iteratore random di lettura e scrittura
	typedef T* iterator;

	// Iteratore random di sola lettura
	typedef const T* const_iterator;

	// Ritorna l'iteratore all'inizio della sequenza dati
	iterator begin() {
		return _buffer;
	}

	// Ritorna l'iteratore alla fine della sequenza dati
	iterator end() {
		return _buffer+_size;
	}

	// Ritorna l'iteratore all'inizio della sequenza dati
	const_iterator begin() const {
		return _buffer;
	}

	// Ritorna l'iteratore alla fine della sequenza dati
	const_iterator end() const {
		return _buffer+_size;
	}

	class iterator {
		T * _ptr;
		//guardiamo se i typedef sono da modificare
	public:
		typedef std::forward_iterator_tag iterator_category;
		typedef T                         value_type;
		//la nostra classe è un array di oggetti T
		typedef ptrdiff_t                 difference_type;
		typedef T*                        pointer;
		typedef T&                        reference;


		iterator() : _ptr(null){
			//!!!
		}

		iterator(const iterator &other) : _ptr(other._ptr) {
			//!!!
		}

		iterator& operator=(const iterator &other) {
			_ptr = other._ptr;
			return *this;
		}

		~iterator() {
			//!!! siccome i dati non sono acquisiti in questo caso, non serve
		}

		// Ritorna il dato riferito dall'iteratore (dereferenziamento)
		reference operator*() const {
			return *_ptr;
		}

		// Ritorna il puntatore al dato riferito dall'iteratore
		pointer operator->() const {
			return _ptr;
		}

		// Operatore di iterazione post-incremento
		iterator operator++(int) {
			iterator tmp(*this);
			++_ptr;
			return *tmp;
		}

		// Operatore di iterazione pre-incremento
		iterator& operator++() {
			++_ptr;
			return *this;
		}

		// Uguaglianza
		bool operator==(const iterator &other) const {
			return _ptr == other._ptr;
		}

		// Diversita'
		bool operator!=(const iterator &other) const {
			return !(*this == other);
		}

		// Solo se serve anche const_iterator aggiungere le seguenti definizioni
		friend class const_iterator;

		// Uguaglianza
		bool operator==(const const_iterator &other) const {
			return _ptr == other._ptr;
		}

		// Diversita'
		bool operator!=(const const_iterator &other) const {
			return _ptr != other._ptr;
		}

		// Solo se serve anche const_iterator aggiungere le precedenti definizioni

	private:
		//Dati membro

		// La classe container deve essere messa friend dell'iteratore per poter
		// usare il costruttore di inizializzazione.
		friend class dbuffer; // !!! Da cambiare il nome!

		// Costruttore privato di inizializzazione usato dalla classe container
		// tipicamente nei metodi begin e end
		explicit const_iterator(T *p) : _ptr(p) {
			//!!!
		}

		// !!! Eventuali altri metodi privati

	}; // classe iterator

	// Ritorna l'iteratore all'inizio della sequenza dati
	iterator begin() {
		return iterator(_buffer));
	}

	// Ritorna l'iteratore alla fine della sequenza dati
	iterator end() {
		return iterator(_buffer + _size);
	}



	class const_iterator {
		//
		T * _ptr;
	public:
		typedef std::forward_iterator_tag iterator_category;
		typedef T                         value_type;
		typedef ptrdiff_t                 difference_type;
		typedef const T*                  pointer;
		typedef const T&                  reference;


		const_iterator() : _ptr(null) {
			//!!!
		}

		const_iterator(const const_iterator &other) : _ptr(other._ptr) {
			//!!!
		}

		const_iterator& operator=(const const_iterator &other) {
			_ptr = other._ptr;
			return *this;
		}

		~const_iterator() {
			//!!!
		}

		// Ritorna il dato riferito dall'iteratore (dereferenziamento)
		reference operator*() const {
			return *_ptr;
		}

		// Ritorna il puntatore al dato riferito dall'iteratore
		pointer operator->() const {
			return _ptr;
		}

		// Operatore di iterazione post-incremento
		const_iterator operator++(int) {
			const_iterator tpm(*this);
			++_ptr;
			return tmp;
		}

		// Operatore di iterazione pre-incremento
		const_iterator& operator++() {
			++_ptr;
			return *this;
		}

		// Uguaglianza
		bool operator==(const const_iterator &other) const {
			return _ptr == other._ptr;
		}

		// Diversita'
		bool operator!=(const const_iterator &other) const {
			return _ptr != other._ptr;
		}

		// Solo se serve anche iterator aggiungere le seguenti definizioni

		friend class iterator;

		// Uguaglianza
		bool operator==(const iterator &other) const {
			return _ptr == other._ptr;
		}

		// Diversita'
		bool operator!=(const iterator &other) const {
			return _ptr != other._ptr;
		}

		// Costruttore di conversione iterator -> const_iterator
		const_iterator(const iterator &other) : _ptr(other._ptr){
			//!!!
		}

		// Assegnamento di un iterator ad un const_iterator
		const_iterator &operator=(const iterator &other) {
			_ptr = other._ptr;
			return *this;
		}

		// Solo se serve anche iterator aggiungere le precedenti definizioni

	private:
		//Dati membro

		// La classe container deve essere messa friend dell'iteratore per poter
		// usare il costruttore di inizializzazione.
		friend class dbuffer; // !!! Da cambiare il nome!

		// Costruttore privato di inizializzazione usato dalla classe container
		// tipicamente nei metodi begin e end
		const_iterator(const T *p) : _ptr(p) {
			//!!!
		}

		const_iterator(){}
		// !!! Eventuali altri metodi privati

	}; // classe const_iterator

	// Ritorna l'iteratore all'inizio della sequenza dati
	const_iterator begin() const {
		return const_iterator(_buffer);
	}

	// Ritorna l'iteratore alla fine della sequenza dati
	const_iterator end() const {
		return const_iterator(_buffer +_size);
	}

	template <typename Q> //stiamo facendo una famiglia di dbuffer
	//abbiamo un costruttore templato che vive in una classe template cioè template^2
	//possiamo avere infiniti costruttori poiche sono templati
	dbuffer(const dbuffer <Q> &other) : _buffer(nullptr), _size(0){
		_buffer = new T[other._size];
		//_buffer type T, other type Q, avviene un cast implicito
		//cast implicito not gud, we need cast esplicito
		try {
		for(unsigned int i = 0; i < other._size; ++i)
			_buffer[i] =static_cast<T> (other._buffer[i]);
		}
		catch(...) {
			delete[] _buffer;
			_buffer = nullptr;
			_size = 0;
			throw;
		}
		_size = other._size;

	} //ognun tipo dbuffer di Q diverso da T ed è templato ma su un tipo Q



};


#endif
