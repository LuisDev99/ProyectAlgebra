
#include <iostream>
#include <string>
#include "AlgebraHandler.h"
using namespace std;
#pragma warning(disable : 4996)


int main() {
	int menu = 0;

	string fileName, punto = ".";

	do {
		cout << "\n1. Sumar matrices\n2. Restar matrices\n3. Multiplicar Matrices\n4. Sacar Determinante\n5. Cambiar la extension del archivo\n6. Salir\nIngrese lo que quiere hacer: ";
		cin >> menu;


		switch (menu) {

		case 1:
			//sumar
			system("cls");
			AlgebraHandler::addMatrix();
			break;
		case 2:
			//Restar
			system("cls");
			AlgebraHandler::substractMatrix();
			break;
		case 3:
			//Multiplicar
			system("cls");
			AlgebraHandler::multiplyMatrix();
			break;
		case 4:
			//Determinante
			system("cls");
			AlgebraHandler::determinantOfMatrix();
			break;

		case 5:
			cout << "\nIngrese la nueva extension (sin el punto .) : ";
			cin >> fileName;
			FileHandler::fileExtension = punto + fileName;
			cout << "\nExtension cambiada, ahora durante la ejecucion del programa todos los archivos a leer o a guardar se escribiran con esta nueva extension \""+ punto + fileName+ "\"!\n\n";
			break;

		}

		
	} while (menu != 6);


}




