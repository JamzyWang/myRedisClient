//
// Created by zheming on 15/11/16.
//

#include "../include/redisString.h"
#include "../include/dataSerialization.h"
#include <iostream>

bool setCommand(ip::tcp::socket &sock) {
    std::string key;
    std::string value;
    std::cin >> key;
    std::cin >> value;
    std::string command = "set";
    std::string serilizatedData = dataSerilize(command, key, value);
    size_t len = boost::asio::write(sock, boost::asio::buffer(serilizatedData));
    if (len == serilizatedData.length()) {
        char response[200];
        boost::system::error_code error;
        sock.read_some(boost::asio::buffer(response), error);
        std::cout << response;
        return true;
    }
    else {
        std::cout << "failed to execute " << command << " " << key << " " << value << std::endl;
        return false;
    }
}

bool getCommand(ip::tcp::socket &sock) {
    std::string key;
    std::cin >> key;
    std::string command = "get";
    std::string serilizatedData = dataSerilize(command, key);
    size_t len = boost::asio::write(sock, boost::asio::buffer(serilizatedData));
    if (len == serilizatedData.length()) {
        char response[200];
        boost::system::error_code error;
        sock.read_some(boost::asio::buffer(response), error);
        std::string responseData = dataDeserilize(response);
        if (responseData == "(nil)") {
            std::cout << responseData << std::endl;
        }
        else {
            std::cout << "\"" << responseData << "\"" << std::endl;
        }
        return true;
    }
    else {
        return false;
    }
}

