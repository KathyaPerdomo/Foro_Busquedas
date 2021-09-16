#include <iostream>

using namespace std;

struct no{
	int data; 
	int state;
};

typedef struct no no_hash;

int funcion(int k,int m,int i){
	return ((k +i) %m);
}
	
// Crea la tabla Hash.
no_hash *Crea_Hash(int m){
	no_hash *temp;
	int i;
	if ((temp = (no_hash*)malloc(m*sizeof(no_hash))) !=NULL){
		for (i = 0; i <m; i++)
		temp[i].state = 0;
		return temp;
	}else{ 
		exit(0);
	}
}

// Inserta un elemento k en la tabla T de dimension m. 
void Inserta_Hash(no_hash *T,int m,int k){
	int j, i = 0;
	do{
		j = funcion(k,m, i);
		if (T[j].state == 0 ||T[j].state == 1){
			T[j].data =k;
			T[j].state = 2;
			return;
		}else{
			i++;
		}
	}while (i <m);
	cout<< "Tabla llena!"<<endl;
}

//Busca elemento k en la tabla de Hash 
int Busca_Hash(no_hash *T,int m,int k,int i){
	int j;
	if (i <m){
		j = funcion(k,m,i);
		if (T[j].state == 0){
			return -1;
		}else{
			if (T[j].state == 1){
				return Busca_Hash(T,m,k,i + 1);
			}else{
				if (T[j].data ==k){
					cout<< "Numero "<< k << " encontrado enla posicion ["<<j<<"]"<<endl;
					return j;
				}else{
					return Busca_Hash(T,m,k,i + 1);
				}
			}
		}
	}
	return -1;
}

//Programa principal. 
void main(){
	
	int m, i, k, p,c;
	no_hash *T;
	
	cout<< "Ingrese dimension del arreglo: ";
	cin>> m;
	cout<< endl;
	int* arreglo =new int[m];
	
	//Crea la tabla de Hash.
	T = Crea_Hash(m);
	
	//Ingreso de elementos a la tabla. 
	for (c = 0;c < m;c++)
	{
		cout<< "Ingrese dato [" << c<< "]: ";
		cin>> arreglo[c];
		k = arreglo[c];
		Inserta_Hash(T, m, k);
	}
	cout<< endl;
	
	//Mostrar tabla de Hash. 
	cout<< "Mostrar tabla de Hash" << endl;
	cout<< endl;
	for (p = 0;p < m;p++)
	{
		cout<< "Posicion ["<<p<<"]: "<<T[p].data<< endl;
	}
	cout<< endl;
	
	//Pedir elemento de busqueda (k). 
	cout<< "Ingrese el numero a ser buscado: ";
	cin>> k;
	i = Busca_Hash(T, m, k, 0);
	
	//Si no lo encuentra despliega mensaje.
	if (i == -1)
		cout<< "Numero no encontrado!"<<endl;
		
	//Liberar memoria de arreglo dinamico.
	delete[] arreglo;
	system("pause");
}
