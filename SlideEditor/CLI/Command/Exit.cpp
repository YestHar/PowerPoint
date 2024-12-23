#include "Exit.hpp"

class Exit : public ICommand {
public:
    void exe() override {
        // Perform any cleanup or final actions
        std::cout << "Exiting...\n";
    }

    bool should_exit() const override {
        return true;  // This command should exit the program
    }
};
