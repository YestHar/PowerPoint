#include "LoadCommand.hpp"
#include "../Document/DocumentSerializer.hpp"
#include "../../Application/Application.hpp"

LoadCommand::LoadCommand(const std::unordered_map<std::string, std::vector<std::variant<std::string, int, double>>> &args)
{
    auto it = args.find("filename");
    if (it != args.end() && !it->second.empty())
    {
        filename = std::get<std::string>(it->second[0]);
    }
    else
    {
        std::cerr << "Invalid or missing argument for filename in Load." << std::endl;
    }

}

void LoadCommand::exe()
{
    Application::get_instance().get_document() = DocumentSerializer::load(filename);
}