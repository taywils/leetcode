#include <iostream>
#include <string>
#include <cassert>
#include <cstdlib>
#include <cmath>
#include <random>
#include <climits>

using namespace std;

int myAtoi(string str) {
    int myInt = 0;
    int myDigit = 0;

    for(int i = str.length() - 1; i > -1; --i) {
        switch(str.at(i)) {
            case '0':
                myInt += (myDigit == 0) ? 0 : (int)(pow(10, (double)myDigit) * 0);
            break;

            case '1': {
                myInt += (myDigit == 0) ? 1 : (int)(pow(10, (double)myDigit) * 1);
            } break;

            case '2': {
                myInt += (myDigit == 0) ? 2 : (int)(pow(10, (double)myDigit) * 2);
            } break;

			case '3':{
						 myInt += (myDigit == 0) ? 3 : (int)(pow(10, (double)myDigit) * 3);
			} break;

			case '4':{
						 myInt += (myDigit == 0) ? 4 : (int)(pow(10, (double)myDigit) * 4);
			} break;

			case '5':{
						 myInt += (myDigit == 0) ? 5 : (int)(pow(10, (double)myDigit) * 5);
			} break;

			case '6':{
						 myInt += (myDigit == 0) ? 6 : (int)(pow(10, (double)myDigit) * 6);
			} break;

			case '7':{
						 myInt += (myDigit == 0) ? 7 : (int)(pow(10, (double)myDigit) * 7);
			} break;

			case '8':{
						 myInt += (myDigit == 0) ? 8 : (int)(pow(10, (double)myDigit) * 8);
			} break;

			case '9':{
						 myInt += (myDigit == 0) ? 9 : (int)(pow(10, (double)myDigit) * 9);
			} break;

			case '-':{
						 myInt *= -1;
			} break;
        }
       ++myDigit; 
    }

    return myInt;
}

class Solution {
public:
	int atoi(const char *str) {
		int myInt = 0;
		int myDigit = 0;

		for (int i = strlen(str) - 1; i >= 0; --i) {
			if ('-' == str[i]) {
				myInt *= -1;
			} else {
				int num = this->charToInt(str[i]);
				myInt += (myDigit == 0) ? num : (int)(pow(10, (double)myDigit) * num);
			}
			++myDigit;
		}

		return myInt;
	}

private:
	int charToInt(char c) {
		switch (c) {
			case '0':
				return 0;
			case '1':
				return 1;
			case '2':
				return 2;
			case '3':
				return 3;
			case '4':
				return 4;
			case '5':
				return 5;
			case '6':
				return 6;
			case '7':
				return 7;
			case '8':
				return 8;
			case '9':
				return 9;
			default:
				return 0;
		}
	}

	const char* cSubStr(const char* cStr, int beginPos, int subStrSize) {
		//http://stackoverflow.com/questions/4214314/get-a-substring-of-a-char
		char* trimedStr = new char[subStrSize]();
		return{ "" };
	}
};

void testValidInts() {
	std::random_device rd;
	std::mt19937 mt{ rd() };
	std::uniform_int_distribution<int> dist{ INT_MIN, INT_MAX };

	Solution solution;
	const int trials = 1000;

	for (int i = 0; i < trials; ++i) {
		int randNum = dist(mt);
		string randNumStr = to_string(randNum);
		const char* randNumCStr = randNumStr.c_str();
		assert(atoi(randNumCStr) == solution.atoi(randNumCStr));
	}
}

void testWackyStringInput() {
	Solution s{};

	const char* leadingWhiteSpace{ " 1245" };
	const char* trailingWhiteSpace{ "1234567   " };
	const char* gaps{ "1 2 3" };
	const char* excessBehind{ "1234   56 7 " };
	const char* excessFront{ " 1 2 34 56789" };
	const char* emptyString{ "" };
	const char* whitespace{ " " };
	const char* nonInt{ "a123" };

	cout << atoi(leadingWhiteSpace) << endl;
	cout << atoi(trailingWhiteSpace) << endl;
	cout << atoi(gaps) << endl;
	cout << atoi(excessBehind) << endl;
	cout << atoi(excessFront) << endl;
	cout << atoi(emptyString) << endl;
	cout << atoi(whitespace) << endl;
	cout << atoi(nonInt) << endl;
	//cout << s.atoi(a) << endl;
	//assert(atoi(a) == s.atoi(a));
}

int main(void) {
	testValidInts();
	testWackyStringInput();
	// style A
	const int seven = 7;
	char foo[seven] = { '\0' };
	strncpy(foo, "bar", 3);
	strncat(foo, "foo", 3);
	cout << foo << endl;
	// style B
	int sev = 7;
	char* bar = new char[sev]();
	strncpy(bar, "foo", 3);
	strncat(bar, "bar", 3);
	bar[sev - 1] = '\0';
	cout << bar << endl;
    return 0;
}