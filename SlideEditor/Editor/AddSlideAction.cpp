#include "AddSlideAction.hpp"
#include "RemoveSlideAction.hpp"


AddSlideAction::AddSlideAction(Slide slide, int index) : currentSlide(slide), slideIndex(index)
{};

std::shared_ptr<IAction> AddSlideAction::do_action(std::shared_ptr<SlideCollection> document) {
    document->addSlide(std::move(std::make_unique<Slide>(currentSlide)), slideIndex);
    return std::make_shared<RemoveSlideAction>(slideIndex);
}


