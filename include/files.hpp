#ifndef FILES_HPP
#define FILES_HPP

#include <string>
#include <vector>

class FileHandler {

public:

    std::string read_file(std::string path);
    std::string overwrite_file(std::string path, std::string content);



};

#endif