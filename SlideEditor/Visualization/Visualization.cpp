#include "Visualization.hpp"

void Visualization::print(std::ostream& os, const SlideCollection& slideCollection, size_t slideIndex) const{
    // Get the slide by index
    const std::shared_ptr<Slide> slide = slideCollection.getSlide(slideIndex);
    if (!slide) {
        os << "Slide " << slideIndex << " not found.\n";
        return;
    }

    // Print slide details
    os << "Slide " << slideIndex << " Details:\n";
    os << "Background Color: " << slide->getBackgroundColor() << "\n";

    // Check if there are no items on the slide
    if (slide->getItemCount() == 0) {
        os << "No items on this slide.\n";
        return;
    }

    // Iterate through the items on the slide
    for (size_t i = 0; i < slide->getItemCount(); ++i) {
        std::shared_ptr<Item> item = slide->getItem(i);
        if (item) {
            os << "Item " << i << " - ";
            os << "Type: " << static_cast<int>(item->get_type()) << "\n"; // Just as a placeholder, type not specified in Item.hpp

            // Print Attributes
            os << "Attributes:\n";
            const auto& attributes = item->get_attributes();
            os << "  - Color: " << attributes.color << "\n";
            os << "  - Border Width: " << attributes.borderWidth << "\n";
            os << "  - Border Color: " << attributes.borderColor << "\n";

            // Print Geometry
            os << "Geometry:\n";
            const Geometry& geometry = item->get_geometry();
            os << "  - X: " << geometry.get_x() << "\n";
            os << "  - Y: " << geometry.get_y() << "\n";
            os << "  - Width: " << geometry.get_width() << "\n";
            os << "  - Height: " << geometry.get_height() << "\n";
        }
    }
}