//
// Created by zheming on 15/11/16.
//

#include "../include/redisCommandRouter.h"
#include "../include/redisString.h"

void redisCommandRouter(ip::tcp::socket &sock, std::string command) {
    if (command == "set") {
        setCommand(sock);
    }
    if (command == "get") {
        getCommand(sock);
    }
}