#include <iostream>
#include "Socket/Server.h"
#include "DataStructures/Matrix_bp.h"
#include"BPGAME/BP_Controller.h"
using namespace std;

int main() {
	//Server::getInstance()->initServer();
	BP_Controller::Init_BP("16");
	
	return 0;
}

