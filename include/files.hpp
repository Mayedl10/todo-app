#ifndef FILES_HPP
#define FILES_HPP

#include <string>
#include <vector>

#include "config.hpp"
#include "tasks.hpp"

class FileHandler {

public:

    std::vector<std::string> list_directory(std::string path);
    void overwrite_file(std::string path, std::string content);
    void delete_file(std::string path);
    void write_task(std::string path, Task& task);

    Task parse_task(std::string path);
    std::vector<Task> parse_all_tasks();

};

#endif