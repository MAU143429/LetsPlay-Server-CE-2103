#pragma once
#include <string>
#include <iostream>
#include "../Util_JSON/JSON_Management.h"
#include "../BPGAME/BP_Controller.h"
#include "../Algorithm/aStar.h"
using namespace std;

class Server_Manager
{

public:
	static void Select_GameController(const string& jsonString) {

		string game = JSON_Management::GetJSONString("Game", jsonString);
		string players = JSON_Management::GetJSONString("Totalplayers", jsonString);
		string currentplayer = JSON_Management::GetJSONString("Player", jsonString);
		int currentx = atoi(JSON_Management::GetJSONString("Currentposx", jsonString).c_str());
		int currenty = atoi(JSON_Management::GetJSONString("Currentposy", jsonString).c_str());
		auto currentpos = new bp_Box();
		auto goal = new bp_Box();
		currentpos->setPosx(currentx);
		currentpos->setPosy(currenty);

		// Crear la respuesta al client justo aca

		if (game == "BPGAME") {

			if (JSON_Management::GetJSONString("Initmode", jsonString) == "TRUE"){

				BP_Controller::getInstance()->Init_BP(players.c_str());
				
				
			}
			else if(JSON_Management::GetJSONString("isAi", jsonString) == "TRUE"){

				// LLAMAR A BACKTRACKING PORQUE ES UN BOT

			}
			else { // Es un player
				if (currentplayer == "1") {
					goal->setPosx(5);
					goal->setPosy(15);
					aStar::aStarSearch(currentpos,goal,currentplayer);
					aStar::printRoute();
					
				}
				else {
					goal->setPosx(5);
					goal->setPosy(0);
					aStar::aStarSearch(currentpos, goal, currentplayer);
					aStar::printRoute();
				}
			}

			
		}
		else if (game == "GPUZZLE") {

			// Llamar a funcion controladora del gp_puzzle 

		}
		
	}

};

