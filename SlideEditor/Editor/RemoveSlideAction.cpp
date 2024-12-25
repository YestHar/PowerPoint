#include "RemoveSlideAction.hpp"
#include "AddSlideAction.hpp"


RemoveSlideAction::RemoveSlideAction(int slideIndex) : slideIndex(slideIndex) {}

std::shared_ptr<IAction> RemoveSlideAction::do_action(std::shared_ptr<SlideCollection> document) {
    auto action = std::make_shared<AddSlideAction>(document->getSlide(slideIndex), slideIndex);
    document->removeSlide(slideIndex);
    return action;
}


