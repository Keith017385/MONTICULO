#pragma once
#include <iostream>
#include <cstring>
using namespace std;
template <typename T>
class NODO
{
private:
	T elemento;
public:
	NODO();
	NODO(T elemento);
	T getNodo();
	void setNodo(T ele);
	~NODO();
};

template<typename T>
inline NODO<T>::NODO()
{
	elemento = T{};
}

template<typename T>
inline NODO<T>::NODO(T elemento)
{
	this->elemento = elemento;
}

template<typename T>
inline T NODO<T>::getNodo()
{
	return elemento;
}

template<typename T>
inline void NODO<T>::setNodo(T ele)
{
	elemento = ele;
}

template<typename T>
inline NODO<T>::~NODO()
{
}
