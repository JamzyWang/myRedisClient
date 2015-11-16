//
// Created by zheming on 15/11/16.
//

#ifndef TEST_REDISHASH_H
#define TEST_REDISHASH_H

#include <boost/asio.hpp>

using namespace boost::asio;

bool hsetCommand(ip::tcp::socket &sock);

bool hgetCommand(ip::tcp::socket &sock);

#endif //TEST_REDISHASH_H
