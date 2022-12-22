#include "RoomNumber.h"
#include <vector>

using namespace std;

int RoomNumber::numberOfSets(int roomNumber) {
    //Constraint
    if (roomNumber < 1 || roomNumber > 1000000) {
        return 0;
    }

    int saver = roomNumber;

    //Dividing digits into vector
    vector<int> digits;
    while (roomNumber) {
        digits.push_back(roomNumber % 10);
        roomNumber /= 10;
    }

    int setCounter = 1; //Final counter of sets needed
    int loopCounter; //Counter inside the loop for most sets
    int sixCounter; // Counter for numbers 6 and 9

    //Nested loop for checking how many sets are needed for entered integer
    for (int i = 0; i < digits.size(); i++) {
        if (digits[i] < 0) continue; //Checking if the number is already checked (line 39 and 43)
        loopCounter = 1;
        sixCounter = 2;

        for (int j = i + 1; j < digits.size(); j++) {
            if (digits[j] < 0) continue;
            if ((digits[i] == 6 || digits[i] == 9) && (digits[j] == 6 || digits[j] == 9)) { //Comparison of numbers i and j if i/j is equal to 6 or 9
                sixCounter++;
                digits[j] = -1;
            }
            else if (digits[i] == digits[j]) { //Comparison of numbers other than 6 and 9
                loopCounter++;
                digits[j] = -1;
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