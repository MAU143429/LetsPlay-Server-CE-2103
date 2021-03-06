#pragma once

#include <string>
#include "../DataStructures/SimplyList.h"
#include "../DataStructures/Random_Box.h"
#include "../DataStructures/bp_Box.h"

using namespace std;
static SimplyLinkedList<Random_Box*>* Empty_List = new SimplyLinkedList<Random_Box*>();
class TypeMessage
{
private:
	string game, gamemode, player, totalPlayers, currentPosX, currentPosY, initMode,isAi;
	SimplyLinkedList<Random_Box*> *playerList = new SimplyLinkedList<Random_Box*>();
    SimplyLinkedList<Random_Box*> *aStarList = new SimplyLinkedList<Random_Box*>();
    

public:
    const string& getAi() const {
        return isAi;
    }   

    void setAi(const string& ai) {
        this->isAi = ai;
    }

    const string& getGame() const {
        return game;
    }

    void setGame(const string& game) {
        this->game = game;
    }

    const string& getGamemode() const {
        return gamemode;
    }

    void setGamemode(const string& gamemode) {
        this->gamemode = gamemode;
    }

    const string& getPlayer() const {
        return player;
    }

    void setPlayer(const string& player) {
        this->player = player;
    }

    const string& getTotalplayers() const {
        return totalPlayers;
    }

    void setTotalplayers(const string& totalPlayers) {
        this->totalPlayers = totalPlayers;
    }

    const string& getCurrentposx() const {
        return currentPosX;
    }

    void setCurrentposx(const string& currentPosX) {
        this->currentPosX = currentPosX;
    }

    const string& getCurrentposy() const {
        return currentPosY;
    }

    void setCurrentposy(const string& currentPosY) {
        this->currentPosY = currentPosY;
    }

    const string& getInitmode() const {
        return initMode;
    }

    void setInitmode(const string& initMode) {
        this->initMode = initMode;
    }


    SimplyLinkedList<Random_Box*> *getPlayerlist() {
        return playerList;
    }

    SimplyLinkedList<Random_Box*>* getAStarList() {
        return aStarList;
    }

};

