#include <iostream>
#include "Socket/Server.h"
#include "BPGAME/bpgame_server.h" 
using namespace std;

int main() {
	//Server::getInstance()->initServer();
	bpgame_server::Create_Matrix();
	int randrow = rand() % 10 + 1;
	int randcol = rand() % 10 + 1;
	

	cout << " randrow: " << randrow << " y el randcollel : " << randcol <<  endl;

	return 0;
}

