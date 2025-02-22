#ifndef TASKS_HPP
#define TASKS_HPP

#include <string>
#include <vector>

class Task {

public:

    std::string title;
    std::string description;
    int ID;

    Task (std::string title, std::string description, int id) {
        this->title = title;
        this->description = description;
        this->ID = id;
    }

};

#endif