#include "RoomNumber.h"
#include <vector>

using namespace std;

int RoomNumber::numberOfSets(int roomNumber) {
    //Constraint
    if (roomNumber < 1 || roomNumber > 1000000) {
        return 0;
    }

    int digits = 0;
    int saver = roomNumber;

    //Dividing integer into digits
    do { roomNumber /= 10; digits++; } while (roomNumber != 0);
    //Creating array sized of number of digits
    vector<int> p(digits);
    //Saving values of digits into array
    for (int i = digits - 1; i >= 0; i--) {
        p[i] = saver % 10;
        saver = saver / 10;
    }

    int setCounter = 1; //Final counter of sets needed
    int loopCounter; //Counter inside the loop for most sets
    int sixCounter; // Counter for numbers 6 and 9

    //Nested loop for checking how many sets are needed for entered integer
    for (int i = 0; i < digits; i++) {
        if (p[i] < 0) continue; //Checking if the number is already checked (line 39 and 43)
        loopCounter = 1;
        sixCounter = 2;

        for (int j = i + 1; j < digits; j++) {
            if (p[j] < 0) continue;
            if ((p[i] == 6 || p[i] == 9) && (p[j] == 6 || p[j] == 9)) { //Comparison of numbers i and j if i/j is equal to 6 or 9
                sixCounter++;
                p[j] = -1;
            }
            else if (p[i] == p[j]) { //Comparison of numbers other than 6 and 9
                loopCounter++;
                p[j] = -1;
            }
        }

        int divider = sixCounter / 2; //Variable for acutal number of sets for numbers 6 and 9

        if (loopCounter > divider && loopCounter > setCounter) {
            setCounter = loopCounter; //Setting up final counter of sets(used in line 53 too)
        }
        else if (divider > loopCounter && divider > setCounter) {
            setCounter = divider;
        }
    }

    return setCounter;
}