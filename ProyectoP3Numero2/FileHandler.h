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


	static void insertarValor(Node *& primerNodo, int val);
	static node loadMatrixFromFile();
	static void saveMatrix(Node *& matrix);


};

