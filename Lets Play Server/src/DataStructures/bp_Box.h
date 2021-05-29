#pragma once
#include <string>
using namespace std;


class bp_Box
{

public:
    int name, posx, posy, h_left, h_right, path_left, path_right, g_left, g_right, value;
    bp_Box() {
        
        this->name = 0;

    }
    

    const int& getValue() const {
        return value;
    }

    void setValue(const int& newvalue) {
        value = newvalue;

    }
    const int& getName() const {
        return name;
    }

    void setName(const int& newname) {
        name = newname;
    }

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

    const int& geth_left() const {
        return h_left;
    }

    void seth_left(const int& newh_left) {
        h_left = newh_left;
    }

    const int& geth_right() const {
        return h_right;
    }

    void seth_right(const int& newh_right) {
        h_right = newh_right;
    }

    const int& getpath_left() const {
        return path_left;
    }

    void setpath_left(const int& newpath_left) {
        path_left = newpath_left;
    }

    const int& getpath_right() const {
        return path_right;
    }

    void setpath_right(const int& newpath_right) {
        path_right = newpath_right;
    }

    const int& getg_left() const {
        return g_left;
    }

    void setg_left(const int& newg_left) {
        g_left = newg_left;
    }

    const int& getg_right() const {
        return g_right;
    }

    void setg_right(const int& newg_right) {
        g_right = newg_right;
    }
};

