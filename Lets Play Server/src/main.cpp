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


void mainv2() {
	string player = "14";
	BP_Controller::getInstance()->Init_BP(player.c_str());
	auto newsms = new TypeMessage();
	newsms->setGame("BPGAME");
	newsms->setCurrentposx("2");
	newsms->setCurrentposy("6");
	newsms->setGamemode("PvP");
	newsms->setInitmode("FALSE");
	newsms->setPlayer("1");
	newsms->setAi("FALSE");


	string astar = JSON_Management::TypeMessageToJSON(newsms);
	Server_Manager::Select_GameController(astar);
}

int main() {

	thread runs(RunServer);
	thread runs2(mainv2);
	runs.join();
	runs2.join();



	return 0;
}

