#ifndef   IVisualization_HPP
#define   IVisualization_HPP

#include <iostream>
#include "../Document/SlideCollection.hpp"

class SlideCollection;

class IVisualization {
public:
    virtual ~IVisualization() = default;
    virtual void print(std::ostream& os, std::shared_ptr<SlideCollection> slideCollection, size_t slideIndex) const = 0;
};

#endif // IVisualization_HPP
