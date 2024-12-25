// #include "ICommand.hpp"



// void Help::exe() {
//     std::cout << "Help Information: Use commands to manage slides and shapes." << std::endl; 
// }

// ChangeSlideBg::ChangeSlideBg(Editor& ed, const std::unordered_map<std::string, std::vector<std::variant<std::string, int, double>>>& args)
//     : editor(ed), slideIndex(-1) { 

//     auto slideIt = args.find("slideIndex");
//     auto colorIt = args.find("color");
//     if (slideIt != args.end() && !slideIt->second.empty()) {
//         slideIndex = std::get<int>(slideIt->second[0]); 
//     } else {
//         std::cerr << "Invalid or missing argument for slide index in ChangeSlideBg." << std::endl;
//     }

//     if (colorIt != args.end() && !colorIt->second.empty()) {
//         color = std::get<std::string>(colorIt->second[0]); 
//     } else {
//         color = ""; 
//     }
// }

// void ChangeSlideBg::exe() {
//     if (slideIndex != -1 && !color.empty()) {
//         editor.changeSlideBackgroundColor(slideIndex, color); 
//         std::cout << "Changed background color of slide " << slideIndex << " to " << color << "." << std::endl;
//     } else {
//         std::cerr << "Failed to change background color: Invalid slide index or color." << std::endl; 
//     }
// }

// SwapSlide::SwapSlide(Editor& ed, const std::unordered_map<std::string, std::vector<std::variant<std::string, int, double>>>& args)
//     : editor(ed), index1(-1), index2(-1) { 

//     auto index1It = args.find("index1");
//     auto index2It = args.find("index2");

//     if (index1It != args.end() && !index1It->second.empty()) {
//         index1 = std::get<int>(index1It->second[0]); 
//     } else {
//         std::cerr << "Invalid or missing argument for index1 in SwapSlide." << std::endl;
//     }

//     if (index2It != args.end() && !index2It->second.empty()) {
//         index2 = std::get<int>(index2It->second[0]); 
//     } else {
//         std::cerr << "Invalid or missing argument for index2 in SwapSlide." << std::endl;
//     }
// }

// void SwapSlide::exe() {
//     if (index1 != -1 && index2 != -1) {
//         editor.swapSlides(index1, index2); 
//         std::cout << "Swapped slides at indices: " << index1 << " and " << index2 << "." << std::endl;
//     } else {
//         std::cerr << "Failed to swap slides: Invalid indices." << std::endl; 
//     }
// }









