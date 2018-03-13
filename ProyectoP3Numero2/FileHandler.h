#pragma once
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


	static void crearFilaDeNodos(Node *& primerNodo, int val);
	static void crearNodo(Node *&nodo, int val);
	static node loadMatrixFromFile();
	static void saveMatrix(Node *& matrix);
	static void crearMatriz(Node *& matriz, int val, int rowCounter);


};

