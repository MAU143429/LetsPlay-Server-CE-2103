#pragma once
#include <string>
#include <iostream>
#include "../Util_JSON/JSON_Management.h"
#include "../BPGAME/bpgame_server.h"

class Server_Manager
{

public:
	void Select_GameController(const string& jsonString) {

		string game = JSON_Management::GetJSONString("game", jsonString);
		// Crear la respuesta al client justo aca

		if (game == "BPGAME") {

			// Llamar a funcion controladora del bp game
		}
		else if (game == "GPUZZLE") {

			// Llamar a funcion controladora del gp_puzzle 

		}

	}


};
