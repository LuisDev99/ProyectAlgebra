#include <iostream>
#include <string>
#include "AlgebraHandler.h"
using namespace std;



int main() {
	int menu = 0;

	do {
		cout << "1. Sumar matrices\n2. Restar matrices\n3. Multiplicar Matrices\n4.Sacar Determinante\nUn numero mayor a 4 para salir\nIngrese lo que quiere hacer: ";
		cin >> menu;


		switch (menu) {

		case 1:
			//sumar
			//system("cls");
			AlgebraHandler::addMatrix();
			break;
		case 2:
			//Restar
			//system("cls");
			AlgebraHandler::substractMatrix();
			break;
		case 3:
			//Multiplicar

			break;
		case 4:
			//Determinante

			break;


		}

		
	} while (menu <= 4 && menu > 0);


}




