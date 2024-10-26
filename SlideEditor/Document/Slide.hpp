#ifndef SLIDE_HPP
#define SLIDE_HPP

#include "Item.hpp"
#include <vector>
#include <memory>
#include <string>
#include <vector>
#include <memory>
#include <iostream>

class Slide {
public:
    void addItem(std::unique_ptr<Item> item) ;

    std::shared_ptr<Item> getItem(size_t index);

    size_t getItemCount() const ;

    void removeItem(size_t index);

    void setBackgroundColor(const std::string& color);
    std::string getBackgroundColor() const;
private:
    std::vector<std::unique_ptr<Item>> items;
    std::string backgroundColor;  

};


#endif // SLIDE_HPP
