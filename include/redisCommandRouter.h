//
// Created by zheming on 15/11/16.
//

#ifndef TEST_REDISCOMMANDROUTER_H
#define TEST_REDISCOMMANDROUTER_H

#include <boost/asio.hpp>

using namespace boost::asio;

void redisCommandRouter(ip::tcp::socket &sock, std::string command);

#endif //TEST_REDISCOMMANDROUTER_H
