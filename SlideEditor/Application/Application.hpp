#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <memory>
#include "../Editor/Editor.hpp"
#include "../Document/SlideCollection.hpp"
#include "../CLI/Parser.hpp"
#include "../Visualization/Visualization.hpp"
#include "../CLI/Controller.hpp"  // Include Controller header

// Forward declaration of Controller class
class Controller;


class Application {
public:
    // Get the singleton instance of Application
    static Application& get_instance();

    // Delete copy constructor and assignment operator to enforce Singleton
    Application(const Application&) = delete;
    Application& operator=(const Application&) = delete;

    // Methods to access the components
    std::shared_ptr<Editor> get_editor() const;
    std::shared_ptr<SlideCollection> get_document() const;
    std::shared_ptr<Parser> get_parser() const;
    std::shared_ptr<Visualization> get_visualization() const;
    std::shared_ptr<Controller> get_controller() const;  // Add access to Controller


    // Run the application (starting point)
    void run();

private:
    // Private constructor to prevent direct instantiation
    Application();

    // Pointers to other components
    std::shared_ptr<Editor> editor;
    std::shared_ptr<SlideCollection> document;
    std::shared_ptr<Parser> parser;
    std::shared_ptr<Visualization> visualization;
    std::shared_ptr<Controller> controller;  // Add controller pointer
};


#endif // APPLICATION_HPP
