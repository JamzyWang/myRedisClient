//
// Created by zheming on 15/11/16.
//


#include <iostream>
#include "../include/redisHash.h"
#include "../include/dataSerialization.h"

bool hsetCommand(ip::tcp::socket &sock) {
    std::string command = "hset";
    std::string key;
    std::string field;
    std::string value;
    std::cin >> key;
    std::cin >> field;
    std::cin >> value;

    std::string serilizatedData = dataSerilize(command, key, field, value);
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

bool hgetCommand(ip::tcp::socket &sock) {
    std::string key;
    std::cin >> key;
    std::string command = "get";
    std::string serilizatedData = dataSerilize(command, key);
    size_t len = boost::asio::write(sock, boost::asio::buffer(serilizatedData));
    if (len == serilizatedData.length()) {
        char response[200];
        boost::system::error_code error;
        sock.read_some(boost::asio::buffer(response), error);
        std::string responseData = deserilizeHgetData(response);
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