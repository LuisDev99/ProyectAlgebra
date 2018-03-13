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


void FileHandler::crearMatriz(Node *& matriz, int val, int rowCount) {

	if (rowCount == 0) {
		crearFilaDeNodos(matriz, val);
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
		crearNodo(tmp->abajo, val);
		nodeBefore->abajo->derecha = tmp->abajo;


		/*if (doneFinishingLine == true) {
			while (tmp->abajo != 0)
				tmp = tmp->abajo;
			crearNodo(tmp->abajo, val);
			return;
		}
			
		while (tmp->abajo != 0) {
			nodeBefore = tmp;
			tmp = tmp->derecha;
		}
		crearNodo(tmp->abajo, val);
		nodeBefore->abajo->derecha = tmp->abajo;*/
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

	if (checkMatrixDimentions(fileName) == false) {
		cout << "Error: La Matriz es irregular(una columna de una fila no es igual que las demas)" << endl;
		return 0;
	}

	node newMatrix = 0, headOfRow = 0, head = 0, nodeBefore = 0;
	string line;
	int value, rowCounter = 0;
	int filas = 0, columnas = 0;
	bool onFirstRow = true, doneFinishingLine = true;

	while (getline(matrixFromFile, line)) { //Por cada linea
		stringstream linestream(line);
		
		while (linestream >> value) { //Por cada valor en la linea
			crearMatriz(newMatrix, value, rowCounter);
			doneFinishingLine = false;
		}
		onFirstRow = false;
		doneFinishingLine = true;
		rowCounter++;
	}
	matrixFromFile.close();
	cout << "== Matriz cargada sin ningun error! ==\n";
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



///OLD WORIKING

//if (doneFinishingLine == true) {
//	while (tmp->abajo != 0)
//		tmp = tmp->abajo;
//	crearNodo(tmp->abajo, val);
//	return;
//}
//
//while (tmp->abajo != 0) {
//	nodeBefore = tmp;
//	tmp = tmp->derecha;
//}
//crearNodo(tmp->abajo, val);
//nodeBefore->abajo->derecha = tmp->abajo;