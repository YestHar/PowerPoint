#include "DocumentSerializer.hpp"
#include "Slide.hpp"
#include "Item.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

// Save the SlideCollection to a text file
void DocumentSerializer::save(const SlideCollection& collection, const std::string& filename) {
    std::ofstream file(filename);
    
    if (!file) {
        std::cerr << "Error: Unable to open file for saving.\n";
        return;
    }

    // Serialize the SlideCollection
    file << "SlideCollection\n";
    for (const auto& slide : collection) {
        file << "Slide\n";
        file << "BackgroundColor: " << slide.getBackgroundColor() << "\n";

        // Serialize items in the slide
        for (size_t i = 0; i < slide.getItemCount(); ++i) {
            std::shared_ptr<Item> item = slide.getItem(i);
            file << "Item " << i << "\n";
            file << "Type: " << static_cast<int>(item->get_type()) << "\n";
            file << "Geometry: " << item->get_geometry().get_x() << "," << item->get_geometry().get_y()
                 << "," << item->get_geometry().get_width() << "," << item->get_geometry().get_height() << "\n";
            file << "Attributes: " << item->get_attributes().color << "," << item->get_attributes().borderWidth
                 << "," << item->get_attributes().borderColor << "\n";
        }
    }
    
    file.close();
}

// Load a SlideCollection from a text file
std::shared_ptr<SlideCollection> DocumentSerializer::load(const std::string& filename) {
    std::ifstream file(filename);
    
    if (!file) {
        std::cerr << "Error: Unable to open file for loading.\n";
        return nullptr;
    }

    auto collection = std::make_shared<SlideCollection>();

    std::string line;
    while (std::getline(file, line)) {
        if (line == "Slide") {
            // Read slide data
            std::string backgroundColor;
            std::getline(file, line); // BackgroundColor line
            std::istringstream(line.substr(17)) >> backgroundColor; // Extract background color

            auto slide = std::make_shared<Slide>();
            slide->setBackgroundColor(backgroundColor);

            // Read items in the slide
            while (std::getline(file, line) && line.find("Item") != std::string::npos) {
                // Read item details
                std::string itemTypeStr;
                std::getline(file, line); // Type line
                std::istringstream(line.substr(6)) >> itemTypeStr;

                EType type = static_cast<EType>(std::stoi(itemTypeStr));
                
                auto item = std::make_shared<Item>(0, 0, 100, 100, Attributes(), type);  // Default geometry and attributes

               

                // Read geometry
                std::getline(file, line); // Geometry line
                int x, y, width, height;
                std::sscanf(line.c_str(), "Geometry: %d,%d,%d,%d", &x, &y, &width, &height);
                item->set_geometry(Geometry(x, y, width, height));

                // Read attributes
                std::getline(file, line); // Attributes line
                std::string color, borderColor;
                int borderWidth;
                std::sscanf(line.c_str(), "Attributes: %[^,],%d,%[^,]", &color[0], &borderWidth, &borderColor[0]);

                item->set_attributes(Attributes(color, borderWidth, borderColor));

                // Add item to slide
                slide->addItem(item);
            }

            // Add slide to collection
            collection->addSlide(slide, collection->getCount());
        }
    }
    
    file.close();
    return collection;
}
