#include <iostream>
#include "Socket/Server.h"
#include "DataStructures/Matrix_bp.h"
#include"BPGAME/BP_Controller.h"
#include "DataStructures/SimplyList.h"
#include "DataStructures/Random_Box.h"
#include "Util_JSON/TypeMessage.h"
using namespace std;

int main() {
	//Server::getInstance()->initServer();
	BP_Controller::Init_BP("12");
	return 0;
}

