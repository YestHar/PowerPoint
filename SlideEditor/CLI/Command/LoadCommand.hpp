#ifndef LOADCOMMAND_HPP
#define LOADCOMMAND_HPP

#include "ICommand.hpp"
#include "../Document/DocumentSerializer.hpp"
#include <string>
#include <memory>

class LoadCommand : public ICommand {
public:
    LoadCommand(const std::string& filename, std::shared_ptr<SlideCollection> slideCollection)
        : filename(filename), slideCollection(slideCollection) {}

    void exe() override {
        DocumentSerializer::load(filename);
    }

private:
    std::string filename;
    std::shared_ptr<SlideCollection> slideCollection;
};

#endif // LOADCOMMAND_HPP
