#include "HEAP.h"
#include <fstream>
int main()
{
	//PROGRAMAR CON MENÚ UN Heap MIN
	//	Es ARRAY SEGÚN SE VIO EN CLASE, traer corriendo los siguientes códigos :
	int op,num;
	HEAP<int> heap(10000);
	do
	{
		cout << "1. INSERTAR al HEAP" << endl;
		cout << "2. ELIMINAR RAIZ" << endl;
		cout << "3. MOSTRAR ARRAY" << endl;
		cout << "4. LEER ARCHIVO 10.000 números" << endl;
		cout << "5. Heap Sort" << endl;
		cout << "10. Salir" << endl;
		cout << "Ingrese opción: "<< endl;
		cin >> op;
		switch (op)
		{
		case 1:
			cout << "Ingrese elemento a insertar: "<<endl;
			cin >> num;
			heap.Insertar(num);
			break;
		case 2:
			heap.EliminarRaiz();
			break;
		case 3:
			heap.mostrarArray();
			break;
		case 4:
		{
			ifstream archivo("10000_Numeros.txt");
			if (!archivo.is_open())
			{
				cout << "No se pudo abrir el archivo" << endl;
				break;
			}
			int numero;
			while (archivo >> numero)
			{
				heap.Insertar(numero);
			}
			archivo.close();
		}
			break;
		case 5:
		{
			vector<NODO<int>> sorted = heap.HeapSort();
			cout << "Heap Sort: ";
			for (int i = 0; i < sorted.size(); i++)
			{
				cout<<" - "<<sorted[i].getNodo();
			}
			cout << endl;
		}
			break;
		default:
			cout << "Opción no válida" << endl;
			break;
		}
	} while (op!=10);
	
	return 0;
}