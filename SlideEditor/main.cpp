#include "Application/Application.hpp"

// Main function connects to Controller
int main() {
    Application& app = Application::get_instance(); 
    app.run(); // Start the application

    return 0;
}
