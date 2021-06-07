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

	auto message = new TypeMessage();
	message->setGame("BPGame");
	auto list = new SimplyLinkedList<Random_Box*>();

	auto box = new Random_Box();
	box->setPosx(1);
	box->setPosx(2);

	message->getPlayerlist()->append(box);

	auto box1 = new Random_Box();
	box1->setPosx(44);
	box1->setPosx(64);

	message->getAStarList()->append(box1);

	cout << JSON_Management::TypeMessageToJSON(message);
	
	return 0;
}

