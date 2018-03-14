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

	while (matrixA == 0) {//Repetir hasta que ingrese un archivo valido
		matrixA = FileHandler::loadMatrixFromFile();
	}
	cout << "\n\tImprimiendo Primera Matriz\n" << endl;
	FileHandler::printMatrix(matrixA);

	node matrixB = FileHandler::loadMatrixFromFile();

	while (matrixB == 0) {//Repetir hasta que ingrese un archivo valido
		matrixB = FileHandler::loadMatrixFromFile();
	}
	cout << "\n\tImprimiendo Segunda  Matriz\n" << endl;
	FileHandler::printMatrix(matrixB);

	if (checkMatricesDimentions(matrixA, matrixB) == false) {
		return;
	}

	node newMatrix = 0, newMatrixPointer = 0;
	node tmpA = matrixA, tmpB = matrixB, tmpC = matrixA;

	int columnsMatrixA = AlgebraHandler::getMatrixColumnsCount(matrixA);
	int count = 0, rowCounter = 0;
	while (tmpC != 0) {
		matrixA = tmpA;
		matrixB = tmpB;
		while (count < columnsMatrixA) {
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

	//Pedir la primera matriz
	node matrixA = FileHandler::loadMatrixFromFile();

	while (matrixA == 0) { //Repetir hasta que ingrese un archivo valido
		matrixA = FileHandler::loadMatrixFromFile();
	}
	cout << "\n\tImprimiendo Primera Matriz\n" << endl;
	FileHandler::printMatrix(matrixA);

	//Pedir la segunda matriz
	node matrixB = FileHandler::loadMatrixFromFile();

	while (matrixB == 0) { //Repetir hasta que ingrese un archivo valido
		matrixB = FileHandler::loadMatrixFromFile();
	}
	cout << "\n\tImprimiendo Segunda Matriz\n" << endl;
	FileHandler::printMatrix(matrixB);


	if (checkMatricesDimentions(matrixA, matrixB) == false) {
		return;
	}

	node newMatrix = 0, newMatrixPointer = 0;
	node tmpA = matrixA, tmpB = matrixB, tmpC = matrixA;
	int columnsMatrixA = AlgebraHandler::getMatrixColumnsCount(matrixA);
	
	int count = 0, rowCounter = 0;
	while (tmpC != 0) {
		matrixA = tmpA;
		matrixB = tmpB;
		while (count < columnsMatrixA) {
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

int AlgebraHandler::getMatrixRowsCount(Node *&matrix) {

	node tmp = matrix;
	int count = 0;


	while (tmp != 0) {
		tmp = tmp->abajo;
		count++;
	}

	return count;
}

bool AlgebraHandler::checkMatricesDimentions(Node *& A, Node *& B)
{
	int columnsMatrixA = AlgebraHandler::getMatrixColumnsCount(A);
	int rowsMatrixA = AlgebraHandler::getMatrixRowsCount(A);

	int columnsMatrixB = AlgebraHandler::getMatrixColumnsCount(B);
	int rowsMatrixB = AlgebraHandler::getMatrixRowsCount(B);


	if (columnsMatrixA != columnsMatrixB || rowsMatrixA != rowsMatrixB) {
		cout << "\nError: Las dimensiones de las matrices no son iguales (En suma o resta de matrices las dos matrices tienen que tener las mismas dimensiones)\n" << endl;
		return false;
	}
	return true;
}
