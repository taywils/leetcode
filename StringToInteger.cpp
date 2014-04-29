#include <iostream>
#include <string>
#include <cassert>
#include <cstdlib>
#include <cmath>

using namespace std;

int myAtoi(string str) {
    int myInt = 0;
    int myDigit = 0;

    for(int i = str.length() - 1; i > -1; --i) {
        switch(str.at(i)) {
            case '0':
                myInt += 0;
            break;

            case '1': {
                myInt += (myDigit == 0) ? 1 : pow(10, myDigit) * 1;
            } break;

            case '2': {
                myInt += (myDigit == 0) ? 2 : pow(10, myDigit) * 2;
            } break;

            case 3:
            break;

            case 4:
            break;

            case 5:
            break;

            case 6:
            break;

            case 7:
            break;

            case 8:
            break;

            case 9:
            break;

            case '-':
            break;
        }
       ++myDigit; 
    }

    return myInt;
}

int main(void) {
    string one = "1";
    string eleven = "11";
    string hund = "100";
    string two = "2";
    string twotwo = "22";
    string twoone = "21";

    assert(atoi(one.c_str()) == myAtoi("1"));
    assert(atoi(eleven.c_str()) == myAtoi("11"));
    assert(atoi(hund.c_str()) == myAtoi("100"));
    assert(atoi(two.c_str()) == myAtoi("2"));
    assert(atoi(twotwo.c_str()) == myAtoi("22"));
    assert(atoi(twoone.c_str()) == myAtoi("21"));

    return 0;
}