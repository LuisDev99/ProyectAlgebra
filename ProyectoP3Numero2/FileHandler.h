#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

typedef struct Node {

	int valor;
	Node *derecha;
	Node *abajo;
} *node;



class FileHandler
{
public:
	FileHandler();
	~FileHandler();

	static std::string fileExtension;
	static void createLineOfNodes(Node *& primerNodo, int val);
	static void createNode(Node *&nodo, int val);
	static node loadMatrixFromFile();
	static void saveMatrix(Node *& matrix);
	static void createMatrix(Node *& matriz, int val, int rowCounter);
	static bool checkMatrixDimentions(std::string file);
	static void printMatrix(Node *&matrix);
	static void saveDeterminant(int valor);

};

