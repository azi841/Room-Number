#include <iostream>
#include "RoomNumber.h"
#include <cassert>
using namespace std;


int main() {
    RoomNumber room;
    //Unit testing
    assert(room.numberOfSets(122) == 2); 
    assert(room.numberOfSets(9999) == 2);
    assert(room.numberOfSets(12635) == 1);
    assert(room.numberOfSets(888888) == 6);
    //Testing if constraint works
    assert(room.numberOfSets(1000001) == 0); 
    assert(room.numberOfSets(0) == 0);
    assert(room.numberOfSets(-1) == 0);
    return 0;
}


