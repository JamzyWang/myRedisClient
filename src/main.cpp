#include <iostream>
#include <boost/asio.hpp>
#include <boost/array.hpp>
#include "../include/dataSerialization.h"
#include "../include/util.h"

using namespace boost::asio;

void executeLoop(ip::tcp::socket &sock, std::string IP, std::string Port);

io_service g_ios;

int main(int argc, char *argv[]) {

    if (checkCommandLineInputs(argc, argv)) {

        std::string ip = "127.0.0.1";//default IP
        std::string port = "6379";//default port
        switch (argc) {
            case 1:
                break;
            case 2:
                ip = argv[1];
                break;
            case 3:
                ip = argv[1];
                port = argv[2];
                break;
            default:
                break;
        }

        ip::tcp::endpoint ep(ip::address_v4::from_string(ip), (unsigned short) (std::stoi(port)));
        ip::tcp::socket sock(g_ios);
        try {
            sock.connect(ep);
            std::cout << "connect to redis server success" << std::endl;
        }
        catch (std::exception &e) {
            std::cerr << e.what() << std::endl;
            std::cout << "Could not connect to Redis at " << ip << ":" << port << ":"
            << "Connection refused" << std::endl;
        }
        executeLoop(sock, ip, port);
    }

    return 0;
}

void executeLoop(ip::tcp::socket &sock, std::string ip, std::string port) {

    std::cout << ip << ":" << port << ">";

    std::string command;
    std::cin >> command;
    while (command != "exit") {
        if (command != "get" && command != "set") {
            std::cout << "(error) ERR unknown command" << "\'" << command << "\'" << std::endl;
        }
        else {
            if (command == "set") {//set key value
                std::string key;
                std::string value;
                std::cin >> key;
                std::cin >> value;
                std::string serilizatedData = dataSerilize(command, key, value);
                size_t len = boost::asio::write(sock, boost::asio::buffer(serilizatedData));
                if (len == serilizatedData.length()) {
                    char response[200];
                    boost::system::error_code error;
                    sock.read_some(boost::asio::buffer(response), error);
                    std::cout << response;
                }
                else {
                    std::cout << "failed to execute " << command << " " << key << " " << value << std::endl;
                }
            }

            if (command == "get") {//get key
                std::string key;
                std::cin >> key;
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
                }
            }
        }//end of else
        std::cout << ip << ":" << port << ">";
        std::cin >> command;
    }//end of while

}