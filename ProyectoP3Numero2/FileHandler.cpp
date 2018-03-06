#include "FileHandler.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

FileHandler::FileHandler()
{
}


FileHandler::~FileHandler()
{
}

void FileHandler::insertarValor(Node *& primerNodo, int val) {

	node newVector = new Node();
	newVector->valor = val;
	newVector->derecha = 0;
	newVector->abajo = 0;

	if (primerNodo == 0) {
		primerNodo = newVector;
		return;
	}
	else {
		node tmp = primerNodo;
		while (tmp->derecha) 
			tmp = tmp->derecha;

		tmp->derecha = newVector;

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

	node newMatrix = 0, head = 0;
	string line;
	int value;
	bool guard = true;

	while (getline(matrix, line)) { //Por cada linea
		stringstream linestream(line);
		
		while (linestream >> value) { //Por cada valor en la linea
	
			insertarValor(newMatrix, value);
		
		}
		
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
