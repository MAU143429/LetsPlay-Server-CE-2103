#pragma once

#include <iostream>
#include <string>
#include <WS2tcpip.h>
#include <mutex>
#pragma comment(lib, "ws2_32.lib")

using namespace std;

class Server
{
protected:
    Server();
    ~Server();
private:
    static Server* unique_instance;
    static mutex mutex_;
public:
    static Server* getInstance();
    /**
     * @brief Method that doesn't let the server instance be cloneable.
     */
    void operator=(const Server&) = delete;

    /**
     * @brief Method that doesn't let the server be assignable.
     * @param other
     */
    Server(Server& other) = delete;
    void initServer();

};