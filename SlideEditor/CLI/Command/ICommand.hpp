#ifndef ICOMMAND_HPP
#define ICOMMAND_HPP

#include <iostream>
#include <unordered_map>
#include <memory>
#include <vector>
#include <string>
#include <variant>
#include "../../Application/Application.hpp"

// class Application;

class ICommand {
public:
    virtual ~ICommand() = default; 
    virtual void exe() = 0;  // Execute the command
    virtual bool should_exit() const { return false; }
};

#endif // ICOMMAND_HPP


// Command to show help information
// class Help : public ICommand {
// public:
//     void exe() override;
// };

// // Command to show slide
// class View : public ICommand {
// private:
//     int slideIndex;
//     Visualization& visualization;

// public:
//     View(Visualization& vis, const std::unordered_map<std::string, std::vector<std::variant<std::string, int, double>>>& args);

//     void exe() override;
// };


// // Command to change the background color of a slide
// class ChangeSlideBg : public ICommand {
// private:
//     Editor& editor; 
//     int slideIndex; 
//     std::string color; 

// public:
//     ChangeSlideBg(Editor& ed, const std::unordered_map<std::string, std::vector<std::variant<std::string, int, double>>>& args);
//     void exe() override;
// };

// // Command to swap two slides
// class SwapSlide : public ICommand {
// private:
//     Editor& editor; 
//     int index1; 
//     int index2; 

// public:
//     SwapSlide(Editor& ed, const std::unordered_map<std::string, std::vector<std::variant<std::string, int, double>>>& args);
//     void exe() override;
// };


