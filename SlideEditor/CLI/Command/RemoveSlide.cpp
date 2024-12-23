#include "RemoveSlide.hpp"

RemoveSlide::RemoveSlide(const std::unordered_map<std::string, std::vector<std::variant<std::string, int, double>>>& args)
        : position(-1) {

        // Extract position from arguments
        auto it = args.find("pos");
        if (it != args.end() && !it->second.empty()) {
            position = std::get<int>(it->second[0]);
        } else {
            std::cerr << "Invalid or missing argument for position in RemoveSlide." << std::endl;
        }
    }

void RemoveSlide::exe() {
    if (position >= 0) {
        // Ensure position is valid before removing the slide
        if (position < 0 || position >= Application::get_instance().get_editor()->getDocument()->getCountOfSlides()) {
            std::cerr << "Invalid position. Slide not removed." << std::endl;
            return;
        }

        // Create the action and pass it to the editor's progress method
        auto remove_action = std::make_shared<RemoveSlideAction>(position);
        Application::get_instance().get_editor()->progress(remove_action);
    } else {
        std::cerr << "Failed to remove slide: Invalid position." << std::endl;
    }
}
