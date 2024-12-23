#ifndef REMOVESLIDEACTION_HPP
#define REMOVESLIDEACTION_HPP

#include "IAction.hpp"



class RemoveSlideAction : public IAction {
public:
    explicit RemoveSlideAction(int slideIndex);

    std::shared_ptr<IAction> do_action(std::shared_ptr<SlideCollection> document) override;

private:
    int slideIndex;
};


#endif // REMOVESLIDEACTION_HPP
