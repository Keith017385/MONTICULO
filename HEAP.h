#pragma once
#include "NODO.h"
#include <iostream>
#include <vector>
using namespace std;
template <typename T>
class HEAP
{
private:
	vector<NODO<T>> heap;
	int ultimo;
public:
	HEAP(int TAM);
	void Insertar(T dato);
	NODO<T> EliminarRaiz();
	void mostrarArray();
	void ArribaAbajo(int pos);
	void AbajoArriba(int hijo, bool continuar);
	vector<NODO<T>> HeapSort();
	~HEAP();
};

template<typename T>
 HEAP<T>::HEAP(int TAM)
{
	 heap.resize(TAM);
	 ultimo = 0;
}

template<typename T>
 void HEAP<T>::Insertar(T dato)
{
	 ultimo++;
	 heap[ultimo].setNodo(dato);
	 int hijo = ultimo;
	 AbajoArriba(hijo,true);
}

template<typename T>
NODO<T> HEAP<T>::EliminarRaiz()
{
	 NODO<T> minimo = heap[1];
	 heap[1] = heap[ultimo];
	 ultimo--;
	 ArribaAbajo(1);
	 return minimo;
}

template<typename T>
 void HEAP<T>::mostrarArray()
{
	 if (ultimo == 0)
	 {
		 return;
	 }
	 else
	 {
		 int i = 0;
		 while (i <= ultimo)
		 {
			 cout << " - " << heap[i].getNodo();
			 i++;
		 }
		 cout << endl;
	 }
	 
}

 template<typename T>
  void HEAP<T>::ArribaAbajo(int pos)
 {
	  int izq = 2 * pos;
	  int der = 2 * pos + 1;
	  int menor = pos;

		  if (izq <= ultimo && heap[izq].getNodo() < heap[menor].getNodo())
		  {
			  menor = izq;
		  }
		  if (der <= ultimo && heap[der].getNodo() < heap[menor].getNodo())
		  {
			  menor = der;
		  }		
		  if (menor != pos)
		  {
			  swap(heap[pos], heap[menor]);
			  ArribaAbajo(menor);
		  }
 }

  template<typename T>
  void HEAP<T>::AbajoArriba(int hijo, bool continuar) {
	  while (hijo > 1 && continuar) {
		  int padre = hijo / 2;

		  if (heap[hijo].getNodo() < heap[padre].getNodo()) {
			  swap(heap[hijo], heap[padre]);
			  hijo = padre;
		  }
		  else {
			  continuar = false;
		  }
	  }
  }

template<typename T>
 vector<NODO<T>> HEAP<T>::HeapSort()
{
	 vector<NODO<T>> salida;
	 while (ultimo>0)
	 {
		 NODO<T> minimo = EliminarRaiz();
		 salida.push_back(minimo);
	 }
	 return salida;
}

template<typename T>
 HEAP<T>::~HEAP()
{
}
