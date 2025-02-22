#include <string>
#include <vector>
#include <fstream>
#include <filesystem>
#include <iostream>

#include "config.hpp"
#include "tasks.hpp"
#include "files.hpp"

std::vector<std::string> FileHandler::list_directory(std::string path) {
    std::vector<std::string> files;

    for (const auto& entry : std::filesystem::directory_iterator(path)) {
        if (entry.is_regular_file() && entry.path().extension() == TASK_EXTENSION) {
            files.push_back(entry.path().filename().string());
        }
    }

    return files;
}


void FileHandler::delete_file(std::string path) {

}

void FileHandler::overwrite_file(std::string path, std::string content) {
    std::ofstream stream(path);
    stream << content;
    stream.close();
}


void FileHandler::write_task(std::string path, Task& task) {
    std::string task_F =  task.title + "\n" + task.description;
    this->overwrite_file(path, task_F);
}

Task FileHandler::parse_task(std::string path) {

    std::ifstream stream(path);

    Task ret("", "", -1);

    std::getline(stream, ret.title);
    std::getline(stream, ret.description);

    std::string filenameWithoutExt = "";
    for (char c: std::filesystem::path(path).filename().string()) {
        if (c == '.') {
            break;
        }
        filenameWithoutExt += c;
    }

    ret.ID = std::stoi(filenameWithoutExt);

    return ret;
}

std::vector<Task> FileHandler::parse_all_tasks() {
    // unsorted! (kinda sorted but like... 1 10 11 2 3 4 5...)
    std::vector<std::string> files = this->list_directory(TASK_FOLDER);

    std::vector<Task> ret = {};

    for (std::string file: files) {
        ret.push_back(this->parse_task(std::string(TASK_FOLDER) + "/" + file));
    }

    return ret;
}