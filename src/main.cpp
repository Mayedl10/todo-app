#include <iostream>

#include "config.hpp"
#include "tasks.hpp"
#include "files.hpp"

int main() {

    FileHandler f = {};

    auto dir = f.list_directory(TASK_FOLDER);

    std::vector<Task> tasks = f.parse_all_tasks();

    std::cout << tasks[0].title << std::endl;
    std::cout << tasks[0].description << std::endl;

    std::cin.get();
    return 0;
}