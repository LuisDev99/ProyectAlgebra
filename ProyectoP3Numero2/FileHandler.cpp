#include "FileHandler.h"
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

FileHandler::FileHandler()
{
}


FileHandler::~FileHandler()
{
}

void FileHandler::crearFilaDeNodos(Node *& primerNodo, int val) 
{
	node newVector = new Node();
	newVector->valor = val;
	newVector->derecha = 0;
	newVector->abajo = 0;

	if (primerNodo == 0) {
		primerNodo = newVector;
		return;
	} else {
		node tmp = primerNodo;

		while (tmp->derecha) {
			tmp = tmp->derecha;
		}

		tmp->derecha = newVector;
	}
}

void FileHandler::crearNodo(Node *& nodo, int val)
{
	node newNode = new Node();
	newNode->valor = val;
	newNode->abajo = 0;
	nodo = newNode;
}


void FileHandler::crearMatriz(Node *& matriz, int val, bool isFirstLine) {

	if (isFirstLine == true) {
		crearFilaDeNodos(matriz, val);
	} else {
		node tmp = matriz, nodeBefore = 0;

		if (tmp->abajo == 0)
			crearNodo(tmp->abajo, val);
		else {
			while (tmp->abajo != 0) {
				nodeBefore = tmp;
				tmp = tmp->derecha;
			}
			crearNodo(tmp->abajo, val);
			nodeBefore->abajo->derecha = tmp->abajo;
		}
	}

}



node FileHandler::loadMatrixFromFile()
{
	string fileName;

	cout << "Ingrese el nombre del archivo de la matriz: ";
	cin >> fileName;

	ifstream matrix(fileName);

	if (!matrix) {
		cout << "Error: Archivo de la matriz no encontrado" << endl;
		return 0;
	}

	node newMatrix = 0, headOfRow = 0, head = 0, nodeBefore = 0;
	string line;
	int value;
	bool onFirstRow = true;

	while (getline(matrix, line)) { //Por cada linea
		stringstream linestream(line);
		
		while (linestream >> value) { //Por cada valor en la linea
			crearMatriz(newMatrix, value, onFirstRow);
		}
		onFirstRow = false;
	}
	matrix.close();
 	return newMatrix;

}


void FileHandler::saveMatrix(Node *&matrix) {

	ofstream writer("Resultado.txt", ios::app);

	node tmp = matrix;
	node head = tmp;
	while (tmp != 0) {

		while (tmp != 0) {
			writer << tmp->valor << ' ';
			tmp = tmp->derecha;
		}
		writer << endl;
		tmp = head->abajo;
		head = tmp;
	}

	writer.close();
}



//OLD
//if (onFirstRow) {
//	crearFilaDeNodos(newMatrix, value);
//
//} else {
//	crearNodo(head->abajo, value);
//	if (head->derecha != 0)
//		head = head->derecha;
//}
//
////USAR VARIBALES TEMP
//
//}
//onFirstRow = false;
//
//if (headOfRow == 0) {
//	head = headOfRow = newMatrix;
//
//} else {
//	head = headOfRow->abajo;
//}