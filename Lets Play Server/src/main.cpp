#include <iostream>
#include "Socket/Server.h"
#include "BPGAME/bpgame_server.h" 
using namespace std;

int main() {
	//Server::getInstance()->initServer();
	bpgame_server::Create_Matrix();
	
	return 0;
}