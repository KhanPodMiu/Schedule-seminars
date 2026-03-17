#pragma once

#include <string>
#include <vector>

class Student {
public:
    int id;
    std::vector<std::string> busy_slot;
};

class Room {
public:
    std::string roomId;
    int capacity;
    std::vector<std::string> availableSlot;
};

class Seminar {
public:
    std::string seminarId;
    std::vector<int> studentId;
};