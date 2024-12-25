#include "Help.hpp"
#include <iostream>

void Help::exe() {
    std::cout << "Help Information: Use commands to manage slides and shapes." << std::endl; 
    std::cout << "add slide -pos <index>: " << std::endl;
    std::cout << "remove slide -pos <index>" << std::endl;
    std::cout << "view slide -slide <slide_id>" << std::endl;
    std::cout << "undo" << std::endl;
    std::cout << "redo" << std::endl;
    std::cout << "save" << std::endl;
    std::cout << "load" << std::endl;
}