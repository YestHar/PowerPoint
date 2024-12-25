#ifndef ICOMMAND_HPP
#define ICOMMAND_HPP

#include <iostream>
#include <unordered_map>
#include <memory>
#include <vector>
#include <string>
#include <variant>



class ICommand {
public:

    virtual ~ICommand() = default; 
    virtual void exe() = 0; // Execute the command
    virtual bool should_exit() const { return false; }
};


#endif // ICOMMAND_HPP


