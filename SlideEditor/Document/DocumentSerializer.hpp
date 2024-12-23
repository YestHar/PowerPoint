#ifndef DOCUMENTSERIALIZER_HPP
#define DOCUMENTSERIALIZER_HPP

#include "SlideCollection.hpp"
#include <fstream>
#include <sstream>
#include <string>
#include <memory>

class DocumentSerializer {
public:
    // Save a SlideCollection (Document) to a file
    static void save(const SlideCollection& collection, const std::string& filename);

    // Load a SlideCollection (Document) from a file
    static std::shared_ptr<SlideCollection> load(const std::string& filename);
};

#endif // DOCUMENTSERIALIZER_HPP
