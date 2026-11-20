#include "config.hpp"
#include <map>


void config::init_config() {

    this->read_config();
    this->parse_config();
    //this->print_token();

    this->self_id = this->token["NAME"];
}


void config::print_token() {

    for (const auto& [key, value] : this->token) {

        std::cout << key << " = " << value << std::endl; 
    } 
}


void config::read_config() {

    std::fstream config_file;

    config_file.open("/home/ege/.msgrc");

    std::getline(config_file, this->config_data);

    config_file.close();
}


void config::parse_config() {
    
    std::string buffer;

    std::string current_key;
    
    for (const auto& i : this->config_data) {

        //std::cout << "i = " << i << std::endl;

        if (i == '=') {

            current_key = buffer;
                        
            this->token.emplace(buffer, "");

            buffer.clear();
        } 
    
        else if (i != '=' && i != ';') {

            buffer.push_back(i); 
            
            //std::cout << "buffer = " << buffer << std::endl;
        }
        
        else if (i == ';') {

            this->token[current_key] = buffer;

            current_key.clear();
        }
    }
}
