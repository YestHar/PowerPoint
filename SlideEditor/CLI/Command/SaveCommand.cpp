#include "SaveCommand.hpp"
#include "../Document/DocumentSerializer.hpp"
#include "../../Application/Application.hpp"

SaveCommand::SaveCommand(const std::unordered_map<std::string, std::vector<std::variant<std::string, int, double>>>& args) {

    auto it = args.find("filename");
    if (it != args.end() && !it->second.empty()) {
        filename = std::get<std::string>(it->second[0]);
    } else {
        std::cerr << "Invalid or missing argument for filename in Save." << std::endl;
    }

}


void SaveCommand::exe() {
    DocumentSerializer::save(*Application::get_instance().get_document(), filename);
}