
#include <iostream>
#include <string>
#include "AlgebraHandler.h"
using namespace std;



int main() {
	int menu = 0;

	do {
		cout << "1. Sumar matrices\n2. Restar matrices\n3. Multiplicar Matrices\n4. Sacar Determinante\n5. Salir\nIngrese lo que quiere hacer: ";
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
			AlgebraHandler::multiplyMatrix();
			break;
		case 4:
			//Determinante
			//system("cls");
			AlgebraHandler::determinantOfMatrix();
			break;


		}

		
	} while (menu != 5);


}




