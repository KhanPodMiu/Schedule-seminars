#include <iostream>
#include "../include/readData.h"
#include <vector>

using namespace std;

int main() {

    vector<Seminar> A;
    readSeminar(A);

    for(auto c : A){
        cout << "Id: " << c.seminarId << endl;
        cout << "Duration: " << c.duration << endl;
        for(int d : c.registed_Students){
            cout << d << " ";
        }
        cout << endl;
    }

    return 0;
}