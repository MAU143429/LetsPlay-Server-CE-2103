#include <iostream>
#include "Socket/Server.h"
#include "DataStructures/Matrix_bp.h"
#include"BPGAME/BP_Controller.h"
#include "DataStructures/SimplyList.h"
#include "DataStructures/Random_Box.h"
#include "Util_JSON/TypeMessage.h"
#include "Socket/Server_Manager.h" 
using namespace std;

void RunServer() {
	cout << "Server is running" << endl;
	Server::getInstance()->initServer();
}



int main() {

	thread runs(RunServer);
	runs.join();

	return 0;
}

