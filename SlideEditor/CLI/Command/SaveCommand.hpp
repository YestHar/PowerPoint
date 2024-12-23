#ifndef SAVECOMMAND_HPP
#define SAVECOMMAND_HPP

#include "../Document/DocumentSerializer.hpp"
#include "ICommand.hpp"
#include <string>
#include <memory>

class Application;

class SaveCommand : public ICommand {
public:

    SaveCommand(const std::string& filename, std::shared_ptr<SlideCollection> slideCollection)
        : filename(filename), slideCollection(slideCollection) {}

    void exe() override {
        DocumentSerializer::save(*slideCollection, filename);
    }

private:
    std::string filename;
    std::shared_ptr<SlideCollection> slideCollection;
};

#endif // SAVECOMMAND_HPP
