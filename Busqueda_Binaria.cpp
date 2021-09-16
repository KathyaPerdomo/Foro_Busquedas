#include <iostream>
#include <conio.h>

using namespace std;

int main(){
  	int num, pun=0, final=9, mitad, vec[10]={3,8,11,22,38,49,50,56,62,70};
  	bool enc = false;
	
	cout<<"Ingrese un numero: ";
	cin>>num;
	
	while(!enc && pun <= final){
		mitad = (int)((pun + final) / 2);
		if(num==vec[mitad])
			enc = true;
		else if(num < vec[mitad])
			final = mitad - 1;
		else
			pun = mitad + 1;
	}
	
	if(enc)
		cout<<"El dato se encuentra en la posicion: " <<mitad + 1;
	else
		cout<<"El dato no se encontro";
	_getch();
}
