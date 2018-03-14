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

void FileHandler::createLineOfNodes(Node *& primerNodo, int val) 
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

void FileHandler::createNode(Node *& nodo, int val)
{
	node newNode = new Node();
	newNode->valor = val;
	newNode->abajo = 0;
	nodo = newNode;
}

void FileHandler::createMatrix(Node *& matriz, int val, int rowCount) {

	if (rowCount == 0) {
		createLineOfNodes(matriz, val);
	} else {
		node tmp = matriz, nodeBefore = 0;
		int row = 1;

		while (row < rowCount) {
			tmp = tmp->abajo;
			row++;
		}
		nodeBefore = tmp;
		while (tmp->abajo != 0) {
			nodeBefore = tmp;
			tmp = tmp->derecha;
		}
		createNode(tmp->abajo, val);
		nodeBefore->abajo->derecha = tmp->abajo;
	}
	

}

bool FileHandler::checkMatrixDimentions(string file)
{
	ifstream fileMatrix(file);
	int valorTemp = 0, filas = 0, columnas = 0;
	string line;
	vector<int> contadorColumnas;

	while (getline(fileMatrix, line)) {
		stringstream values(line);
		while (values >> valorTemp) {
			columnas++;
		}
		contadorColumnas.push_back(columnas);
		columnas = 0;
	}
	fileMatrix.close();


	for (int i = 0; i < contadorColumnas.size(); i++)
	{
		for (int j = 0; j < contadorColumnas.size(); j++)
		{
			if (contadorColumnas[i] != contadorColumnas[j])
				return false;
		}
	}
	return true;

}

void FileHandler::printMatrix(Node *& matrix)
{

	node tmp = matrix;
	node head = tmp;
	while (tmp != 0) {

		while (tmp != 0) {
			cout << tmp->valor << ' ';
			tmp = tmp->derecha;
		}
		cout << endl;
		tmp = head->abajo;
		head = tmp;
	}

}

void FileHandler::saveDeterminant(int valor)
{
	string filename;

	cout << "Ingrese el nombre del archivo en el que desea guardar el resultado: ";
	cin >> filename;

	ofstream writer(filename);

	writer << "La determinante de la matriz es: " << valor << '\n';
	writer.close();

}

node FileHandler::loadMatrixFromFile()
{
	string fileName;

	cout << "Ingrese el nombre del archivo de la matriz: ";
	cin >> fileName;

	ifstream matrixFromFile(fileName);

	if (!matrixFromFile) {
		cout << "Error: Archivo de la matriz no encontrado" << endl;
		return 0;
	}

	if (checkMatrixDimentions(fileName) == false) { //verificar que las columnas de cada fila de la matriz tengan el mismo tamaño
		cout << "Error: La Matriz es irregular, una columna de una fila no es igual que las demas(Asegurese que las columnas de cada fila tengan el mismo tamaño)" << endl;
		return 0;
	}

	node newMatrix = 0;
	string line;
	int value = 0, rowCounter = 0;

	while (getline(matrixFromFile, line)) { //Por cada linea
		stringstream linestream(line);
		
		while (linestream >> value) { //Por cada valor en la linea
			createMatrix(newMatrix, value, rowCounter);
		}
		rowCounter++;
	}

	matrixFromFile.close();
	cout << "== Matriz cargada sin ningun error! ==\n";
	return newMatrix;

}

void FileHandler::saveMatrix(Node *&matrix) {
	string fileName;
	cout << "Ingrese el nombre con el que desea guardar el archivo con la matriz resultante: ";
	cin >> fileName;

	ofstream writer(fileName, ios::app);

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
	cout << "\nHecho! Revisar el archivo con el resultado" << endl;
	writer.close();
}
