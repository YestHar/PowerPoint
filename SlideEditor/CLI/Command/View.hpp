#ifndef VIEW_HPP
#define VIEW_HPP

#include "ICommand.hpp"
#include <iostream>

class View : public ICommand {
private:
    int slideIndex;
public:
    View( const std::unordered_map<std::string, std::vector<std::variant<std::string, int, double>>>& args);

    void exe() override;
};


#endif // VIEW_HPP

