#ifndef VISUALIZATION_HPP
#define VISUALIZATION_HPP

#include "IVisualization.hpp"
#include "../Document/SlideCollection.hpp"
#include "../Document/Slide.hpp"
#include "../Document/Item.hpp"
#include <memory>
#include <iostream>

class Visualization : public IVisualization {
private:
    std::shared_ptr<SlideCollection> slideCollection;

public:
    // Constructor to initialize slide collection
    Visualization(std::shared_ptr<SlideCollection> document) : slideCollection(document) {}

    // Print the details of a specified slide
    void print(std::ostream& os, const SlideCollection& slideCollection, size_t slideIndex) const override;
};

#endif // VISUALIZATION_HPP
