#ifndef TASKS_HPP
#define TASKS_HPP

#include <string>
#include <vector>

class Task {

public:

    std::string title;
    std::string description;

    Task (std::string title, std::string description) {
        this->title = title;
        this->description = description;
    }

};

#endif