#include <iostream>
#include "../include/readData.h"
#include <vector>

using namespace std;

int main() {

    vector<Room> A;
    readRoom(A);

    for(auto c : A){
        cout << "Room: "<< c.roomId << endl;
        cout << "Capacity: " << c.capacity << endl;
        for(auto d : c.available_Slot){
            cout << "Day: " << d.first << ". Time " << d.second << endl;
        }
    }

    return 0;
}