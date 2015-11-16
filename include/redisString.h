//
// Created by zheming on 15/11/16.
//

#ifndef TEST_REDISSTRING_H
#define TEST_REDISSTRING_H

#include <boost/asio.hpp>

using namespace boost::asio;

bool setCommand(ip::tcp::socket &sock);

bool getCommand(ip::tcp::socket &sock);

#endif //TEST_REDISSTRING_H
