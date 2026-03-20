#pragma once

#include <string>
#include <vector>

class Student{
public:
    int studentId;
    std::vector<std::pair<std::string, std::string>> busy_Slot;
};

class Room{
public:
    std::string roomId;
    int capacity;
    std::vector<std::pair<std::string, std::string>> available_Slot;
};

class Seminar{
public:
    int seminarId;
    int duration;
    std::vector<int> registed_Students;
};