//
// Created by zheming on 15/11/15.
//

#ifndef TEST_DATASERIALIZATION_H
#define TEST_DATASERIALIZATION_H

#include <string>

std::string dataSerilize(std::string command, std::string key);

std::string dataSerilize(std::string command, std::string key, std::string value);

std::string dataSerilize(std::string command, std::string key, std::string field, std::string value);

std::string deserilizeGetData(char responseData[]);

std::string deserilizeHgetData(char responseData[]);

void deserilizeHgetallData(char responseData[]);

#endif //TEST_DATASERIALIZATION_H
