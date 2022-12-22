#include "RoomNumber.h"
#include <vector>
using namespace std;

int RoomNumber::numberOfSets(int number) {
    int digits = 0;
    int saver = number;

    //Dividing integer into digits
    do { number /= 10; digits++; } while (number != 0);
    //Creating array sized of number of digits
    vector<int> p(digits);
    //Saving values of digits into array
    for (int i = digits - 1; i >= 0; i--) {
        p[i] = saver % 10;
        saver = saver / 10;
    }

    int setCounter = 1;
    int loopCounter;
    int sixCounter;
    //Nested loop for checking how many sets are needed for entered integer
    for (int i = 0; i < digits; i++) {
        if (p[i] < 0) continue;
        loopCounter = 1;
        sixCounter = 2;

        for (int j = i + 1; j < digits; j++) {
            if (p[j] < 0) continue;
            if ((p[i] == 6 || p[i] == 9) && (p[j] == 6 || p[j] == 9)) {
                sixCounter++;
                p[j] = -1;
            }
            else if (p[i] == p[j]) {
                loopCounter++;
                p[j] = -1;
            }
        }

        int divider = sixCounter / 2;

        if (loopCounter > divider && loopCounter > setCounter) {
            setCounter = loopCounter;
        }
        else if (divider > loopCounter && divider > setCounter) {
            setCounter = divider;
        }
    }

    return setCounter;
}