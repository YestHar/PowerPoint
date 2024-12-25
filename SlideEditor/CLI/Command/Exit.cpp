#include "Exit.hpp"
#include "iostream"



void Exit::exe() {
    // Perform any cleanup or final actions
    std::cout << "Exiting...\n";
}

bool Exit::should_exit() const  {
    return true;  // This command should exit the program
}

