#ifndef   IVisualization_HPP
#define   IVisualization_HPP

#include <iostream>
#include "../Document/SlideCollection.hpp"

class SlideCollection; // Forward declaration of Slide

class IVisualization {
public:
    virtual ~IVisualization() = default;
    virtual void print(std::ostream& os, const SlideCollection& slideCollection, size_t slideIndex) const = 0;
};

#endif // IVisualization_HPP
