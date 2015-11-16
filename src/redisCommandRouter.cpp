//
// Created by zheming on 15/11/16.
//

#include "../include/redisCommandRouter.h"
#include "../include/redisString.h"
#include "../include/redisHash.h"

void redisCommandRouter(ip::tcp::socket &sock, std::string command) {
    if (command == "set") {
        setCommand(sock);
    }
    if (command == "get") {
        getCommand(sock);
    }
    if (command == "hset") {
        hsetCommand(sock);
    }
    if (command == "hget") {
        hgetCommand(sock);
    }
    if (command == "hgetall") {
        hgetallCommand(sock);
    }
}