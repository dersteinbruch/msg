#ifndef IO_HPP
#define IO_HPP


#include <ctime>
#include <string>
#include <boost/asio.hpp>
#include "config.hpp"


using boost::asio::ip::tcp;


class io {

public:
    explicit io(config& cfg);
    
    void init(const int& argc, char** argv);

    void write_socket();

    void read_socket();

    std::string current_date();
    std::string current_time();

    //void connection_setup(const tcp::socket& socket);


private:
    boost::asio::io_context io_context;

    tcp::socket socket;

    boost::system::error_code error;

    config& cfg;
};


#endif //IO_HPP
