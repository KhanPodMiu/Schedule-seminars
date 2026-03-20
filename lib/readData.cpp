#include "../include/readData.h"
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>

using namespace std;

void readStudent(vector<Student>& A){
    fstream rd("../data/student.csv");

    if(!rd.is_open()){
        cout << "Loi roi...";
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
}