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
	node matrixA = FileHandler::loadMatrixFromFile();
	node matrixB = FileHandler::loadMatrixFromFile();

	if (matrixA == 0 || matrixB == 0) {
		return;
	}

	node newMatrix = 0;

	node headA = matrixA, headB = matrixB;

	while (matrixA != 0) {

		while (matrixA != 0) {
			FileHandler::insertarValor(newMatrix, (matrixA->valor + matrixB->valor));
			matrixA = matrixA->derecha;
			matrixB = matrixB->derecha;
		}

		matrixA = headA->abajo;
		matrixB = headB->abajo;
		headA = matrixA;
		headB = matrixB;
	}
	cout << "Haciendo calculos....." << endl;
	//_sleep(300);
	cout << "Hecho! Revisar el archivo con el resultado" << endl;

	FileHandler::saveMatrix(newMatrix);


}

void AlgebraHandler::substractMatrix() {



}

void AlgebraHandler::multiplyMatrix() {

	

}

void AlgebraHandler::determinantOfMatrix() {



}

