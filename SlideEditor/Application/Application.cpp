#include "Application.hpp"


// Static instance of Application for Singleton pattern
Application& Application::get_instance() {
    static Application instance;  // The single instance
    return instance;
}

Application::Application() {
    // Private constructor ensures this is only called once
    document = std::make_shared<SlideCollection>();
    editor = std::make_shared<Editor>(document);
    parser = std::make_shared<Parser>();
    visualization = std::make_shared<Visualization>(document);
    controller = std::make_shared<Controller>(); // Initialize Controller
}

std::shared_ptr<Editor> Application::get_editor() const {
    return editor;
}

std::shared_ptr<SlideCollection> Application::get_document() const {
    return document;
}

std::shared_ptr<Parser> Application::get_parser() const {
    return parser;
}

std::shared_ptr<Visualization> Application::get_visualization() const {
    return visualization;
}

std::shared_ptr<Controller> Application::get_controller() const {
    return controller;
}

void Application::initialize() {
    // Here we could initialize any further components if needed
    // For example, setup logging, configuration, etc.
}

void Application::run() {
    // Start the program by calling the Controller's start method
    controller->startProgram();  // This could be the entry point for the app
}



