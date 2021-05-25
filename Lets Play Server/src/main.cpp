#include <iostream>
#include "Socket/Server.h"
#include "BPGAME/bpgame_server.h" 
#include "DataStructures/Matrix_Utilities.h"
using namespace std;

int main() {
	//Server::getInstance()->initServer();
	auto matrix = new Matrix_Utilities(5, 5);
	matrix->printMatrix();


	return 0;
}

