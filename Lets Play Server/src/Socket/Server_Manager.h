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
	/**
	 * @brief Method that selects the game using the key in the json string
	 * @param jsonString the string json used for analyzing the keys
	 * @return the typemessage.h object serialized into json string
	*/
	static string Select_GameController(const string& jsonString) {

		string game = JSON_Management::GetJSONString("Game", jsonString);
		string players = JSON_Management::GetJSONString("Totalplayers", jsonString);
		string currentplayer = JSON_Management::GetJSONString("Player", jsonString);
		int currentx = atoi(JSON_Management::GetJSONString("Currentposx", jsonString).c_str());
		int currenty = atoi(JSON_Management::GetJSONString("Currentposy", jsonString).c_str());
		auto currentpos = new bp_Box();
		auto goal = new bp_Box();
		currentpos->setPosx(currentx);
		currentpos->setPosy(currenty);
		auto response = new TypeMessage();


		// Crear la respuesta al client justo aca

		if (game == "BPGAME") {

			if (JSON_Management::GetJSONString("Initmode", jsonString) == "TRUE"){

				

				SimplyLinkedList<Random_Box*> * final_players = BP_Controller::getInstance()->Init_BP(players.c_str());
				response->setGame("BPGAME");
				response->setInitmode("TRUE");

				for (int i = 0; i < final_players->getLen(); i++)
				{
					response->getPlayerlist()->append(final_players->get(i));
				}

				string result = JSON_Management::TypeMessageToJSON(response);
				return result;
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
					auto aStarList = aStar::getRouteList();
					for (int i = 0; i < aStarList->getLen(); i++)
					{
						response->getAStarList()->append(aStarList->get(i));
					}

					string result = JSON_Management::TypeMessageToJSON(response);
					return result;
				
				}
				else {
					goal->setPosx(5);
					goal->setPosy(0);
					aStar::aStarSearch(currentpos, goal, currentplayer);
					aStar::printRoute();
					auto aStarList = aStar::getRouteList();
					for (int i = 0; i < aStarList->getLen(); i++)
					{
						response->getAStarList()->append(aStarList->get(i));
					}

					string result = JSON_Management::TypeMessageToJSON(response);
					return result;
				}
			}
			
			response->setGame("GPGAME");
			response->setCurrentposx("14");
			response->setCurrentposy("7");
			response->setGamemode("PvAi");
			response->setInitmode("TRUE");
			response->setPlayer("2");
			response->setAi("FALSE");
			
			return JSON_Management::TypeMessageToJSON(response);
			
		}
		else if (game == "GPUZZLE") {

			// Llamar a funcion controladora del gp_puzzle 

		}
		
	}

};

