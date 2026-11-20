#include <iostream>
#include <thread>
#include <boost/asio.hpp>
#include "io.hpp"
#include "config.hpp"


using boost::asio::ip::tcp;


int main(int argc, char* argv[]) {

    try {

        config cfg;

        cfg.init_config();

	    io io(cfg);

        io.init(argc, argv);

        std::jthread writing_thread([&] { io.write_socket(); });
        std::jthread reading_thread([&] { io.read_socket(); });
    }	

    catch (std::exception& e) {
    
        std::cout << e.what() << std::endl;    
    }

    return 0;
}
