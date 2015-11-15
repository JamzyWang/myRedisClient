//
// Created by zheming on 15/11/14.
//

#include <iostream>
#include <regex>
#include "../include/util.h"

bool isIPAddress(const std::string ip) {
    //Todo
    std::regex ipRegex("((?:(?:25[0-5]|2[0-4]\\d|((1\\d{2})|([1-9]?\\d)))\\.){3}(?:25[0-5]|2[0-4]\\d|((1\\d{2})|([1-9]?\\d))))");
    return std::regex_match(ip,ipRegex);
}

bool isHostPort(const std::string port) {
    //Todo
    bool isPort = false;
    try{
        int portNum = std::stoi(port);
        if(portNum>0 && portNum < 65536){
            isPort = true;
        }
    }
    catch(std::exception e) {
        isPort = false;
    }
    return isPort;
}

bool checkCommandLineInputs(const int argc, char *argv[]) {
    bool rightCommandLineInputs;
    switch (argc) {
        case 1:
            rightCommandLineInputs = true;
            break;
        case 2:
            if (isIPAddress(argv[1])) {
                rightCommandLineInputs = true;
                break;
            }
            else {
                std::cout << "wrong IP address" << std::endl;
                rightCommandLineInputs = false;
                break;
            }
        case 3:
            if (isIPAddress(argv[1]) && isHostPort(argv[2])) {
                rightCommandLineInputs = true;
                break;
            }
            else {
                if (!isIPAddress(argv[1])) {
                    std::cout << "wrong IP address" << std::endl;
                    rightCommandLineInputs = false;
                    break;
                }
                else {
                    std::cout << "wrong Host Port" << std::endl;
                    rightCommandLineInputs = false;
                    break;
                }
            }
        default:
            std::cout << "myRedis-Cli takes 2 arguments" << std::endl;
            rightCommandLineInputs = false;
            break;
    }
    return rightCommandLineInputs;
}
