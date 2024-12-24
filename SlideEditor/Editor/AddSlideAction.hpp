#ifndef ADDSLIDEACTION_HPP
#define ADDSLIDEACTION_HPP

#include "IAction.hpp"
#include "../Document/Slide.hpp"
#include "iostream"

class AddSlideAction : public IAction {
public:
    // explicit AddSlideAction(Slide slide, int slideIndex);
    explicit AddSlideAction(std::shared_ptr<Slide> slide, int slideIndex);
    explicit AddSlideAction(int index);


    std::shared_ptr<IAction> do_action(std::shared_ptr<SlideCollection> document) override;

private:
    int slideIndex;
    // Slide currentSlide;
    std::shared_ptr<Slide> currentSlide;
};


#endif // ADDSLIDEACTION_HPP

