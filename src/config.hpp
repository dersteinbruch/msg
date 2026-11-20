#ifndef CONFIG_HPP 
#define CONFIG_HPP 


#include <iostream>
#include <fstream>
#include <string>
#include <map>


class config {

public:
// PUBLIC METHODS
    void init_config();

    void print_token();

    void read_config();

    void parse_config();

// PUBLIC DATA
    std::string self_id;

private:
    std::string config_data;

    std::map<std::string, std::string> token;
};


#endif //CONFIG_HPP
