//
// Created by zheming on 15/11/14.
//

#include <iostream>
#include <boost/asio.hpp>
#include "../include/connectRedisServer.h"

using namespace boost::asio;

bool connectRedisServer(std::string ip, std::string port) {
    io_service iosev;
    ip::tcp::socket socket(iosev);
    ip::tcp::endpoint ep(ip::address_v4::from_string(ip), (unsigned short) (std::stoi(port)));
    boost::system::error_code ec;
    socket.connect(ep, ec);
    if (ec) {
        std::cout << boost::system::system_error(ec).what() << std::endl;
        socket.close();
        return false;
    }
    else {
        socket.close();
        return true;
    }
}
