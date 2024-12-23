#ifndef IACTION_HPP
#define IACTION_HPP

#include "../Document/SlideCollection.hpp"
#include <memory>

class IAction : public std::enable_shared_from_this<IAction> {
public:
    virtual ~IAction() = default;

    // Executes the action and returns a pointer to the inverse action
    virtual std::shared_ptr<IAction> do_action(std::shared_ptr<SlideCollection> document) = 0;
};


#endif // IACTION_HPP
