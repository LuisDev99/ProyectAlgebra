#pragma once
#include "FileHandler.h"


class AlgebraHandler
{
public:
	AlgebraHandler();
	~AlgebraHandler();
	static void addMatrix();
	static void substractMatrix();
	static void multiplyMatrix();
	static void determinantOfMatrix();
	static int getMatrixColumnsCount(Node*& matrix);
	static int getMatrixRowsCount(Node *& matrix);
	static bool checkMatricesDimentions(Node *& A, Node *&B);
	static int getDeterminant2x2(Node *&matrix);
	static int getDeterminant3x3(Node *&matrix);
	
};

