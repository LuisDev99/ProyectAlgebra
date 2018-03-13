#include "AlgebraHandler.h"
#include <iostream>


using namespace std;

AlgebraHandler::AlgebraHandler()
{
}


AlgebraHandler::~AlgebraHandler()
{
}

void AlgebraHandler::addMatrix() {
	bool onFirstRow = true;
	node matrixA = FileHandler::loadMatrixFromFile();
	node matrixB = FileHandler::loadMatrixFromFile();


	while (matrixA == 0) //Repetir hasta que ingrese un archivo valido
		matrixA = FileHandler::loadMatrixFromFile();

	while (matrixB == 0) //Repetir hasta que ingrese un archivo valido
		matrixB = FileHandler::loadMatrixFromFile();

	node newMatrix = 0, newMatrixPointer = 0;

	node headA = matrixA, headB = matrixB;

	while (matrixA != 0 && matrixB != 0) {


		while (headA != 0 && headB != 0) {

			if (onFirstRow == true) {
				FileHandler::createLineOfNodes(newMatrix, (headA->valor + headB->valor));
				headA = headA->derecha;
				headB = headB->derecha;
			} else {
				FileHandler::createNode(newMatrix->abajo, (headA->valor + headB->valor));
				headA = headA->derecha;
				headB = headB->derecha;
				newMatrix = newMatrix->derecha;
			}
		}
		onFirstRow = false;
		
		headA = matrixA->abajo;
		headB = matrixB->abajo;

		matrixA = headA;
	}


	//Efectos visuales
	cout << "Haciendo calculos";
	/*Sleep(500);
	cout << ".";
	Sleep(500);
	cout << ".";
	Sleep(500);
	cout << ".";
	Sleep(500);
	cout << ".";
	Sleep(500);
	cout << ".";
	Sleep(500);
	cout << "." << endl;
	Sleep(100);
	system("cls");*/
	cout << "Hecho! Revisar el archivo con el resultado" << endl;

	FileHandler::saveMatrix(newMatrix);


}

void AlgebraHandler::substractMatrix() {



}

void AlgebraHandler::multiplyMatrix() {

	

}

void AlgebraHandler::determinantOfMatrix() {



}

/*while (matrixA != 0) {
if (onFirstRow == true) {
FileHandler::crearFilaDeNodos(newMatrix, (matrixA->valor + matrixB->valor));
matrixA = matrixA->derecha;
matrixB = matrixB->derecha;
} else {

FileHandler::crearNodo(newMatrix, (matrixA->valor + matrixB->valor));
matrixA = matrixA->derecha;
matrixB = matrixB->derecha;

}
}
onFirstRow = false;
matrixA = headA->abajo;
matrixB = headB->abajo;
headA = matrixA;
headB = matrixB;*/