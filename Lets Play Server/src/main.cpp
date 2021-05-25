#include <iostream>
#include "Socket/Server.h"
#include "DataStructures/Matrix_bp.h"
using namespace std;

int main() {
	//Server::getInstance()->initServer();
	auto matrix = new Matrix_bp(5, 5);
	matrix->printMatrix();
	matrix->fill_Matrix();
	matrix->printMatrix();
	


	return 0;
}

