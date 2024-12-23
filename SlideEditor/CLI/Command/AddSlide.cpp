#include "AddSlide.hpp"

AddSlide::AddSlide(const std::unordered_map<std::string, std::vector<std::variant<std::string, int, double>>>& args)
    : position(-1) {

    // Extract position from arguments
    auto it = args.find("pos");
    if (it != args.end() && !it->second.empty()) {
        position = std::get<int>(it->second[0]);
    } else {
        std::cerr << "Invalid or missing argument for position in AddSlide." << std::endl;
    }
}

void AddSlide::exe() {
    if (position >= 0) {
        // Create a new slide with a unique name based on the current slide count
        auto slide = std::make_unique<Slide>("Slide " + std::to_string(Application::get_instance().get_editor()->getDocument()->getCountOfSlides() + 1));
        
        // Ensure position is valid before adding the slide
        if (position < 0 || position > Application::get_instance().get_editor()->getDocument()->getCountOfSlides()) {
            std::cerr << "Invalid position. Slide not added." << std::endl;
            return;
        }

        // Create the action and pass it to the editor's progress method
        auto add_action = std::make_shared<editor::AddSlideAction>(*slide, position);
        Application::get_instance().get_editor()->progress(add_action);
    } else {
        std::cerr << "Failed to add slide: Invalid position." << std::endl;
    }
}
