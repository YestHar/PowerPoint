#include "RemoveSlideAction.hpp"
#include "AddSlideAction.hpp"


RemoveSlideAction::RemoveSlideAction(int slideIndex) : slideIndex(slideIndex) {}

std::shared_ptr<IAction> RemoveSlideAction::do_action(std::shared_ptr<SlideCollection> document) {
    document->removeSlide(slideIndex);
    return std::make_shared<AddSlideAction>(slideIndex);
}


