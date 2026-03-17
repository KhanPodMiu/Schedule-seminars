#pragma once

#include <string> 
#include <vector> 

using namespace std;

class student{
    public:
        int id;
        vector<string> busy_slot;
};

class room{
    public:
        string roomId;
        int capacity;
        vector<string> availableSlot;
};

class seminar{
    public:
        string seminarId;
        vector<int> studentId;
};