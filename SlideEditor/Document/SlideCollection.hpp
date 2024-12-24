#ifndef SLIDECOLLECTION_HPP
#define SLIDECOLLECTION_HPP

#include <vector>
#include <memory>
#include <iterator>
#include "Slide.hpp"

// SlideCollection to manage multiple slides
class SlideCollection {
private:
    std::vector<std::shared_ptr<Slide>> slides; 

public:
    void addSlide(std::shared_ptr<Slide> slide, int position);
    size_t getCount() const;
    std::shared_ptr<Slide> getSlide(size_t index) const;
    size_t getCountOfSlides() const;
    void removeSlide(size_t index);
    void swapSlides(int index1, int index2);

    class const_iterator {
    private:
        const SlideCollection& collection;
        size_t index;

    public:
        const_iterator(const SlideCollection& coll, size_t idx) : collection(coll), index(idx) {}

        const_iterator& operator++() { 
            ++index; 
            return *this; 
        }
        
        bool operator!=(const const_iterator& other) const { 
            return index != other.index; 
        }
        
        const Slide& operator*() const { 
            return *collection.slides[index];
        }
    };

    const_iterator begin() const {
        return const_iterator(*this, 0);
    }

    const_iterator end() const {
        return const_iterator(*this, slides.size());
    }
};


#endif // SLIDECOLLECTION_HPP