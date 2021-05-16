#include <iostream>
#include "Socket/Server.h"
using namespace std;

int main() {
	Server::getInstance()->initServer();
	return 0;
}