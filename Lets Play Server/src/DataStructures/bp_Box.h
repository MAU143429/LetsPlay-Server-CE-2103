#pragma once
#include <string>
using namespace std;


class bp_Box
{

public:
    int name,parent_x,parent_y, posx, posy,value;
    double h, f, g;
    bp_Box() {
        
        this->value = 0;
    }
    
    const int& getParentx() const {
        return parent_x;
    }

    void setParentx(const int& newpx) {
        parent_x = newpx;

    }

    const int& getParenty() const {
        return parent_y;
    }

    void setParenty(const int& newpy) {
        parent_y = newpy;

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

    const double& get_h() const {
        return h;
    }

    void set_h(const double& new_h) {
        h = new_h;
    }

    const double& get_f() const {
        return f;
    }

    void set_f(const double& new_f) {
        f = new_f;
    }

    const double& get_g() const {
        return g;
    }

    void set_g(const double& new_g) {
        g = new_g;
    }

};

