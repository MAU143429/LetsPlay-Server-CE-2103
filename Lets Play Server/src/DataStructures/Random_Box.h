#pragma once
#include <string>
using namespace std;


class Random_Box
{

public:

	int posx, posy;

    const int& getPosx() const {
        return posx;
    }

    void setPosx(const int& newposx) {
        posx = newposx;
    }

    const int& getPosy() const {
        return posy;
    }

    void setPosy(const int& newposy) {
        posy = newposy;
    }

};

