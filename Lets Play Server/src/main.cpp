#include <iostream>
#include "Socket/Server.h"
#include "BPGAME/bpgame_server.h" 
#include "DataStructures/Matrix_Utilities.h"
using namespace std;

int main() {
	//Server::getInstance()->initServer();
	auto matrix = new Matrix_Utilities(2, 1);
	matrix->printMatrix();


	return 0;
}

