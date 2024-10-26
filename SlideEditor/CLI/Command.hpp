#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <iostream>
#include <unordered_map>
#include <memory>
#include <vector>
#include <string>
#include <variant>
#include "../Editor/Editor.hpp"

class Editor;

class ICommand {
public:
    virtual ~ICommand() = default; 
    virtual void exe() = 0; 
};

// Command to add a slide
class AddSlide : public ICommand {
private:
    Editor& editor; 
    int position; 

public:
    AddSlide(Editor& ed, const std::unordered_map<std::string, std::vector<std::variant<std::string, int, double>>>& args);
    void exe() override;
};

// Command to remove a slide
class RemoveSlide : public ICommand {
private:
    Editor& editor;
    int slideIndex; 

public:
    RemoveSlide(Editor& ed, const std::unordered_map<std::string, std::vector<std::variant<std::string, int, double>>>& args);
    void exe() override;
};

// Command to exit the application
class Exit : public ICommand {
public:
    void exe() override;
};

// Command to show help information
class Help : public ICommand {
public:
    void exe() override;
};

// Command to show slide
class View : public ICommand {
public:
    void exe() override;
};

// Command to change the background color of a slide
class ChangeSlideBg : public ICommand {
private:
    Editor& editor; 
    int slideIndex; 
    std::string color; 

public:
    ChangeSlideBg(Editor& ed, const std::unordered_map<std::string, std::vector<std::variant<std::string, int, double>>>& args);
    void exe() override;
};

// Command to swap two slides
class SwapSlide : public ICommand {
private:
    Editor& editor; 
    int index1; 
    int index2; 

public:
    SwapSlide(Editor& ed, const std::unordered_map<std::string, std::vector<std::variant<std::string, int, double>>>& args);
    void exe() override;
};

#endif // COMMAND_HPP
