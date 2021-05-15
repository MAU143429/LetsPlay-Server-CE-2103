//
// Created by jonas on 5/14/2021.
//

#ifndef LET_S_PLAY_SERVER_SERVER_H
#define LET_S_PLAY_SERVER_SERVER_H
#include <iostream>
#include <mutex>

using namespace std;

class Server {
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
    void operator=(const Server &) = delete;

    /**
     * @brief Method that doesn't let the server be assignable.
     * @param other
     */
    Server(Server &other) = delete;
    void initServer();
};


#endif //LET_S_PLAY_SERVER_SERVER_H
