#include "../include/readData.h"
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>

using namespace std;

void readStudent(vector<Student>& A){
    fstream rd("data/student.csv");

    if(!rd.is_open()){
        cout << "Loi doc student roi...";
        return ;
    }

    string line;
    getline(rd, line);

    while(getline(rd, line)){
        stringstream ss(line);

        string studentId;
        string timeTable;
        
        getline(ss, studentId, ',');
        getline(ss, timeTable);

        Student s;

        s.studentId = stoi(studentId);
        string eachDay;
        stringstream sss(timeTable);
        while(getline(sss, eachDay, ';')){
            s.busy_Slot.push_back({eachDay.substr(0,3), eachDay.substr(4, eachDay.size())});
        }
        A.push_back(s);
    }

    rd.close();
}

void readRoom(vector<Room>& B){
    fstream rd("data/rooms.csv");

    if(!rd.is_open()){
        cout << "Loi doc room roi...";
        return ;
    }

    string line;
    getline(rd, line);

    while(getline(rd, line)){
        stringstream ss(line);

        string roomId;
        string capacity;
        string availableSlots;
        
        getline(ss, roomId, ',');
        getline(ss,capacity, ',');
        getline(ss, availableSlots);

        Room s;

        s.roomId = roomId;
        s.capacity = stoi(capacity);

        stringstream sss(availableSlots);

        string cell;

        while (getline(sss, cell, ';'))
        {
            s.available_Slot.push_back({cell.substr(0,3), cell.substr(4, cell.size())});
        }
        B.push_back(s);
    }

    rd.close();
}

void readSeminar(std::vector<Seminar>& C){
    fstream rd("data/seminars.csv");

    if(!rd.is_open()){
        cout << "Loi doc seminar roi...";
        return ;
    }

    string line;
    getline(rd, line);

    while(getline(rd, line)){
        stringstream ss(line);

        string seminarId;
        string duration;
        string studentId;

        getline(ss, seminarId, ',');
        getline(ss, duration, ',');
        getline(ss, studentId);

        Seminar s;

        s.seminarId = stoi(seminarId);
        s.duration = stoi(duration);

        stringstream sss(studentId);

        string cell;

        while (getline(sss, cell, ';'))
        {
            s.registed_Students.push_back(stoi(cell));
        }
        C.push_back(s);
    }

    rd.close();
}