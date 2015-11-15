//
// Created by zheming on 15/11/14.
//

#ifndef TEST_UTIL_H
#define TEST_UTIL_H

#include <string>

bool isIPAddress(const std::string ip);

bool isHostPort(const std::string port);

bool checkCommandLineInputs(const int argc, char *argv[]);

#endif //TEST_UTIL_H
