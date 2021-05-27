#pragma once
#include <string>
#include <iostream>
#include "../Util_JSON/JSON_Management.h"
#include "../BPGAME/BP_Controller.h"
using namespace std;

class Server_Manager
{

public:
	void Select_GameController(const string& jsonString) {

		string game = JSON_Management::GetJSONString("game", jsonString);
		string players = JSON_Management::GetJSONString("players", jsonString);
		// Crear la respuesta al client justo aca

		if (game == "BPGAME") {

			BP_Controller::Init_BP(players.c_str());
		}
		else if (game == "GPUZZLE") {

			// Llamar a funcion controladora del gp_puzzle 

		}

	}


};

