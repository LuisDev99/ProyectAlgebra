#include "AlgebraHandler.h"
#include <iostream>
#include <vector>
#include <Windows.h>
#pragma warning(disable : 4996)

using namespace std;

#define VERDADERO true

AlgebraHandler::AlgebraHandler()
{
}


AlgebraHandler::~AlgebraHandler()
{
}

void AlgebraHandler::addMatrix() {

	cout << "\n ########## SUMA DE MATRICES ########## \n";

	node matrixA = FileHandler::loadMatrixFromFile();

	if (matrixA == 0) {
		return;
	}
	cout << "\n\tImprimiendo Primera Matriz\n" << endl;
	FileHandler::printMatrix(matrixA);

	node matrixB = FileHandler::loadMatrixFromFile();

	if (matrixB == 0) {
		return;
	}

	cout << "\n\tImprimiendo Segunda  Matriz\n" << endl;
	FileHandler::printMatrix(matrixB);

	if (checkMatricesDimentions(matrixA, matrixB) == false) {
		return;
	}

	node newMatrix = 0;
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
	AlgebraHandler::specialEffects();

	FileHandler::saveMatrix(newMatrix);
	cout << "\n\tImprimiendo la Matriz Resultante\n" << endl;
	FileHandler::printMatrix(newMatrix);

	delete newMatrix, matrixA, matrixB;
	cout << endl;
}

void AlgebraHandler::substractMatrix() {
	cout << "\n ########## RESTA DE MATRICES ########## \n";

	//Pedir la primera matriz
	node matrixA = FileHandler::loadMatrixFromFile();

	if (matrixA == 0) {
		return;
	}
	cout << "\n\tImprimiendo Primera Matriz\n" << endl;
	FileHandler::printMatrix(matrixA);

	node matrixB = FileHandler::loadMatrixFromFile();

	if (matrixB == 0) {
		return;
	}

	cout << "\n\tImprimiendo Segunda  Matriz\n" << endl;
	FileHandler::printMatrix(matrixB);

	if (checkMatricesDimentions(matrixA, matrixB) == false) { //verificar que as matrices tengan el mismo tamaño n x n
		return;
	}

	node newMatrix = 0;
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
	AlgebraHandler::specialEffects();

	FileHandler::saveMatrix(newMatrix);
	cout << "\n\tImprimiendo la Matriz Resultante\n" << endl;
	FileHandler::printMatrix(newMatrix);
	cout << endl;

}

void AlgebraHandler::multiplyMatrix() {
	cout << "\n ########## MULTIPLICACION DE MATRICES ########## \n";

	node matrixA = FileHandler::loadMatrixFromFile();

	if (matrixA == 0) {
		return;
	}
	cout << "\n\tImprimiendo Primera Matriz\n" << endl;
	FileHandler::printMatrix(matrixA);

	node matrixB = FileHandler::loadMatrixFromFile();

	if (matrixB == 0) {
		return;
	}

	cout << "\n\tImprimiendo Segunda  Matriz\n" << endl;
	FileHandler::printMatrix(matrixB);

	int columnsMatrixA = AlgebraHandler::getMatrixColumnsCount(matrixA);
	int rowsMatrixA = AlgebraHandler::getMatrixRowsCount(matrixA);
	int columnsMatrixB = AlgebraHandler::getMatrixColumnsCount(matrixB);
	int rowsMatrixB = AlgebraHandler::getMatrixRowsCount(matrixB);

	if (columnsMatrixA != rowsMatrixB) {
		cout << "Error: No se puede hacer la multiplicion de estas matrices! Las columnas de la primera matriz tienen que ser iguales a las filas de la segunda matriz\n";
		return;
	}

	int rowCounter = 0;

	node newMatrix = 0;
	node tmpA = matrixA, tmpB = matrixB, tmpC = matrixA;

	node helperTmpA = tmpA, helperTmpB = tmpB;
	while (tmpC != 0) {

		tmpA = helperTmpA;
		tmpB = helperTmpB;
		int contador = 0;

		while (contador < columnsMatrixB) {
			int resultado = 0;

			while (tmpA != 0) {
				resultado += tmpA->valor * tmpB->valor;
				tmpA = tmpA->derecha;
				tmpB = tmpB->abajo;
			}

			FileHandler::createMatrix(newMatrix, resultado, rowCounter);
			tmpA = helperTmpA;
			helperTmpB = helperTmpB->derecha;
			tmpB = helperTmpB;
			contador++;
			resultado = 0;
		}

		helperTmpA = helperTmpA->abajo;
		helperTmpB = matrixB;
		tmpC = tmpC->abajo;
		rowCounter++;
	}

	//Efectos Visuales
	AlgebraHandler::specialEffects();

	FileHandler::saveMatrix(newMatrix);
	cout << "\n\tImprimiendo la Matriz Resultante\n" << endl;
	FileHandler::printMatrix(newMatrix);
	cout << endl;

}

void AlgebraHandler::determinantOfMatrix() {
	cout << "\n ########## DETERMINANTE DE MATRIZ ########## \n";

	node matrix = FileHandler::loadMatrixFromFile();

	if (matrix == 0) 
		return;

	int columns = AlgebraHandler::getMatrixColumnsCount(matrix);
	int rows = AlgebraHandler::getMatrixRowsCount(matrix);

	if (rows != columns) {
		cout << "\nLa matriz es irregular, las filas y columnas tienen que ser iguales (1 x 1, 2 x 2, 3 x 3)\n";
		return;
	}

	if (rows >= 4 || columns >= 4) {
		cout << "\nLa matriz tiene que ser : 1 x 1, 2 x 2, 3 x 3, no mayor a eso(en este proyecto)\n";
		return;
	}

	node tmp = matrix; 

	int determinant = ((rows != 1) ? ((rows == 2) ? getDeterminant2x2(matrix) : getDeterminant3x3(matrix)) : tmp->valor); //Dependiendo del tamaño de la matriz, se llamara a su funcion respectiva
	
	//Efectos Visuales
	AlgebraHandler::specialEffects();

	cout << "La determinante es: " << determinant << endl;
	FileHandler::saveDeterminant(determinant);

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

int AlgebraHandler::getDeterminant2x2(Node *& matrix)
{
	node tmp = matrix;
	node helper = tmp;
	int x1, x2, y1, y2;

	x1 = tmp->valor;
	x2 = tmp->abajo->derecha->valor;
	y1 = tmp->derecha->valor;
	y2 = tmp->abajo->valor;
	
	return (x1 * x2) - (y1 * y2);

}

int AlgebraHandler::getDeterminant3x3(Node *& matrix)
{
	node tmp = matrix;
	node helper = tmp;

	int a11, a12, a13;
	int a21, a22, a23;
	int a31, a32, a33;

	a11 = tmp->valor;
	a12 = tmp->derecha->valor;
	a13 = tmp->derecha->derecha->valor;
	a21 = tmp->abajo->valor;
	a22 = tmp->abajo->derecha->valor;
	a23 = tmp->abajo->derecha->derecha->valor;
	a31 = tmp->abajo->abajo->valor;
	a32 = tmp->abajo->abajo->derecha->valor;
	a33 = tmp->abajo->abajo->derecha->derecha->valor;

	return ((a11 * a22 * a33) + (a12 * a23 * a31) + (a21*a32*a13)) - ((a13 * a22 * a31) + (a12 * a21 * a33) + (a23 * a32 * a11));


}

void AlgebraHandler::specialEffects() {

	cout << "Haciendo calculos";
	Sleep(500);
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

}