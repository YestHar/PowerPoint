#include "View.hpp"
#include "../../Application/Application.hpp"

View::View(const std::unordered_map<std::string, std::vector<std::variant<std::string, int, double>>>& args)
    :  slideIndex(-1) {

    auto it = args.find("id");
    if (it != args.end() && !it->second.empty()) {
        slideIndex = std::get<int>(it->second[0]);
    } else {
        std::cerr << "Invalid or missing slide index in View command." << std::endl;
    }
}

void View::exe() {
    if (slideIndex != -1) {
        std::cout << "Displaying Slide " << slideIndex << ":\n";
        Application::get_instance().get_visualization()->print(std::cout, Application::get_instance().get_document(), slideIndex);
    } else {
        std::cerr << "Failed to view slide: Invalid slide index." << std::endl;
    }
}