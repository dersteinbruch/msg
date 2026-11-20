#include "io.hpp"
#include <iostream>
#include <array>
#include <string>


using boost::asio::ip::tcp;


io::io(config& cfg) :
    cfg(cfg),
    socket(io_context) {}


void io::init(const int& argc, char** argv) {

    if (argc == 2) {

        std::cout << "-- Initiation" << std::endl;
        std::cout << "-- Role: Client" << std::endl;
        std::cout << "-- Date: " + this->current_date();

        tcp::resolver resolver(this->io_context);

        tcp::resolver::results_type endpoints = resolver.resolve(argv[1], "daytime");

        boost::system::error_code error;

        boost::asio::connect(this->socket, endpoints, error);
    }

    else if (argc == 1) {

        std::cout << "-- Initiation" << std::endl;
        std::cout << "-- Role: Host" << std::endl;
        std::cout << "-- Date: " + this->current_date();

        tcp::acceptor acceptor(this->io_context, tcp::endpoint(tcp::v4(), 13));

        acceptor.accept(socket);
    }
}


void io::write_socket() {

    while (true) {

        std::string message;

        std::getline(std::cin, message);
    
        message = this->current_time() + " - " + this->cfg.self_id + ": " + message;

        this->socket.write_some(boost::asio::buffer(message));

        if (this->error == boost::asio::error::eof) {break;}
    }
}


void io::read_socket() {

    while (true) {

        std::array<char, 128> message;

        std::size_t lenght = this->socket.read_some(boost::asio::buffer(message), this->error);

        std::cout.write(message.data(), lenght);

        std::cout << std::endl;

        if (this->error == boost::asio::error::eof) {break;}
    }
}


std::string io::current_date() {

    std::time_t raw_time = time(nullptr);
    
    return ctime(&raw_time);
}


std::string io::current_time() {

    std::time_t raw_time = time(nullptr);

    std::string current_date = ctime(&raw_time);

    std::string current_time = current_date.substr(11, 5);
    
    return current_time;
}


/*
void io::send_setup(const tcp::socket& socket) {

    std::string data;

    data.append("PEERID=" + this->config.self_id);

    socket.write_some(boost::asio::buffer(data));
}


void io::receive_setup(const tcp::socket& socket) {

    std::string data;

    socket.read_some(boost::asio::buffer(data));

    std::string current_data;

    std::string loop_buffer;

    for (const auto& i : data) {
        
        if (i == '=' && loop_buffer == "PEERID") {

                
        } 

        else if (i != '=' && i != ';') {

            loop_buffer.push_back(i);
        }

        else if (i == ';') {

        }
    }
}*/
