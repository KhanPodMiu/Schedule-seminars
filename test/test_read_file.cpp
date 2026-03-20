#include <iostream>
#include "../include/readData.h"
#include <vector>

using namespace std;

int main() {

    vector<Student> A;
    readStudent(A);

    for(auto c : A){
        cout << c.studentId << " ";
        for(auto d : c.busy_Slot){
            cout << "Day " << d.first << ". Times of day " << d.second << endl;
        }
    }

    return 0;
}