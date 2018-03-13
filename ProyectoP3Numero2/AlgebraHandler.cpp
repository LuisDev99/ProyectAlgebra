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
	cout << "\n\tImprimiendo Primera Matriz\n" << endl;
	FileHandler::printMatrix(matrixA);

	while (matrixB == 0) //Repetir hasta que ingrese un archivo valido
		matrixB = FileHandler::loadMatrixFromFile();
	cout << "\n\tImprimiendo Segunda  Matriz\n" << endl;
	FileHandler::printMatrix(matrixB);

	node newMatrix = 0, newMatrixPointer = 0;
	node tmpA = matrixA, tmpB = matrixB, tmpC = matrixA;

	int filasDeLaMatriz = AlgebraHandler::getMatrixColumnsCount(matrixA);
	int count = 0, rowCounter = 0;
	while (tmpC != 0) {
		matrixA = tmpA;
		matrixB = tmpB;
		while (count < filasDeLaMatriz) {
			FileHandler::createMatrix(newMatrix, matrixA->valor + matrixB->valor, rowCounter);
			matrixA = matrixA->derecha;
			matrixB = matrixB->derecha;
			count++;
		}

		tmpA = tmpA->abajo;
		tmpB = tmpB->abajo;

		rowCounter++;
		count = 0;
		tmpC = tmpC->abajo;
	}


	//Efectos visuales
	//cout << "Haciendo calculos";
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

	FileHandler::saveMatrix(newMatrix);
	cout << "\n\tImprimiendo la Matriz Resultante\n" << endl;
	FileHandler::printMatrix(newMatrix);
	cout << endl;


}

void AlgebraHandler::substractMatrix() {
	bool onFirstRow = true;
	node matrixA = FileHandler::loadMatrixFromFile();
	node matrixB = FileHandler::loadMatrixFromFile();


	while (matrixA == 0) //Repetir hasta que ingrese un archivo valido
		matrixA = FileHandler::loadMatrixFromFile();
	cout << "\n\tImprimiendo Primera Matriz\n" << endl;
	FileHandler::printMatrix(matrixA);

	while (matrixB == 0) //Repetir hasta que ingrese un archivo valido
		matrixB = FileHandler::loadMatrixFromFile();
	cout << "\n\tImprimiendo Segunda Matriz\n" << endl;
	FileHandler::printMatrix(matrixB);

	node newMatrix = 0, newMatrixPointer = 0;
	node tmpA = matrixA, tmpB = matrixB, tmpC = matrixA;

	int x = AlgebraHandler::getMatrixColumnsCount(matrixA);
	int count = 0, rowCounter = 0;
	while (tmpC != 0) {
		matrixA = tmpA;
		matrixB = tmpB;
		while (count < x) {
			FileHandler::createMatrix(newMatrix, matrixA->valor - matrixB->valor, rowCounter);
			matrixA = matrixA->derecha;
			matrixB = matrixB->derecha;
			count++;
		}

		tmpA = tmpA->abajo;
		tmpB = tmpB->abajo;

		rowCounter++;
		count = 0;
		tmpC = tmpC->abajo;
	}


	//Efectos visuales
	//cout << "Haciendo calculos";
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
	FileHandler::saveMatrix(newMatrix);
	cout << "\n\tImprimiendo la Matriz Resultante\n" << endl;
	FileHandler::printMatrix(newMatrix);
	cout << endl;

}

void AlgebraHandler::multiplyMatrix() {

	

}

void AlgebraHandler::determinantOfMatrix() {



}

int AlgebraHandler::getMatrixColumnsCount(Node*& matrix)
{

	node tmp = matrix;
	int count = 0;

	while (tmp != 0) {
		tmp = tmp->derecha;
		count++;
	}

	return count;
}
