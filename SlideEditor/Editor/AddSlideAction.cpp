#include "AddSlideAction.hpp"
#include "RemoveSlideAction.hpp"

AddSlideAction::AddSlideAction(std::shared_ptr<Slide> slide, int index) : currentSlide(slide), slideIndex(index)
{};

AddSlideAction::AddSlideAction(int index): slideIndex(index){}



std::shared_ptr<IAction> AddSlideAction::do_action(std::shared_ptr<SlideCollection> document) {
    document->addSlide(currentSlide, slideIndex);
    return std::make_shared<RemoveSlideAction>(slideIndex);
}


