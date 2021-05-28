#pragma once

#include <string>
#include "../DataStructures/SimplyList.h"
#include "../DataStructures/Random_Box.h"

using namespace std;

class TypeMessage
{
private:
	string game, gamemode;
	SimplyLinkedList<Random_Box*> *playerList = new SimplyLinkedList<Random_Box*>();

public:
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

    SimplyLinkedList<Random_Box*> *getPlayerlist() {
        return playerList;
    }
};

