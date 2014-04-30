#include <iostream>
#include <string>
#include <cassert>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <random>
#include <climits>

using namespace std;

class Solution {
public:
	int atoi(const char *inputStr) {
		int myInt = 0;
		int myDigit = 0;
		string intMaxStr = to_string(INT_MAX);
		string intMinStr = to_string(INT_MIN);
		string inputCppStr{ inputStr };

		string cppStr{ this->prepareStr(inputCppStr) };

		if (cppStr.length() == 0) return 0;
		if (cppStr == intMaxStr) return INT_MAX;
		if (cppStr == intMinStr) return INT_MIN;

		bool overflow = false;

		for (int i = cppStr.length() -1; i >= 0; --i) {
			if ('-' == cppStr[i]) {
				if (overflow) return INT_MIN;
				myInt *= -1;
			} else {
				int num = this->charToInt(cppStr[i]);
				myInt += (myDigit == 0) ? num : (int)(pow(10, (double)myDigit) * num);
				if (myInt < 0) overflow = true;
			}
			++myDigit;
		}
		if (overflow) return INT_MAX;
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

	string prepareStr(string cppStr) {
		bool neg = false;
		if(cppStr.length() == 0) {
			return { "" };
		}
		// Remove leading whitespace
		int idx = 0;
		for(auto s : cppStr) {
			if(' ' == s) {
				++idx;
			} else {
				break;
			}
		}
		cppStr = cppStr.substr(idx);
		
		// Check for negative sign
		if ('-' == cppStr[0]) {
			neg = true;
			cppStr = cppStr.substr(1);
		}

		// Remove leading zeros
		idx = 0;
		for (auto s : cppStr) {
			if ('0' == s) {
				++idx;
			}
			else {
				break;
			}
		}
		cppStr = cppStr.substr(idx);

		idx = 0;
		// Remove trailing whitespace
		for(auto s : cppStr) {
			if(' ' == s) {
				break;
			} else {
				++idx;
			}
		}
		if(idx > 0) {
			cppStr = cppStr.substr(0, idx);
		}
		// Truncate if char isalpha
		idx = 0;
		for(auto s : cppStr) {
			if (isalpha(s) || s == ' ' || s == '+' || s == '-') {
				break;
			} else {
				++idx;
			}
		}
		tempStr = cppStr.substr(0, idx);
		if (neg) {
			tempStr = '-' + tempStr;
		}
		return tempStr;
	}

	string tempStr;
};

void testValidInts() {
	std::random_device rd;
	std::mt19937 mt{ rd() };
	std::uniform_int_distribution<int> dist{ INT_MIN, INT_MAX };

	Solution solution;
	const int trials = 10000;

	for (int i = 0; i < trials; ++i) {
		int randNum = dist(mt);
		string randNumStr = to_string(randNum);
		char* randNumCStr = new char[randNumStr.length() + 1];
		strcpy(randNumCStr, randNumStr.c_str());
		assert(atoi(randNumCStr) == solution.atoi(randNumCStr));
		delete[] randNumCStr;
	}

	string largerThanMax{"2147483648"};
	char* cltm = new char[largerThanMax.length() + 1];
	strcpy(cltm, largerThanMax.c_str());

	string smallerThanMin{"-2147483649"};
	char* cstm = new char[smallerThanMin.length() + 1];
	strcpy(cstm, smallerThanMin.c_str());

	assert(INT_MAX == solution.atoi(cltm));
	assert(INT_MIN == solution.atoi(cstm));

	delete[] cstm;
	delete[] cltm;
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
	const char* nonIntChar{ "  -0012a42" };
	const char* startNonInt{ "x 123 " };
	const char* a{ "a" };
	const char* leadingSpaceAndZeroWithGap{ "  -0 451" };

	assert(atoi(leadingWhiteSpace) == s.atoi(leadingWhiteSpace));
	assert(atoi(trailingWhiteSpace) == s.atoi(trailingWhiteSpace));
	assert(atoi(gaps) == s.atoi(gaps));
	assert(atoi(excessBehind) == s.atoi(excessBehind));
	assert(atoi(excessFront) == s.atoi(excessFront));
	assert(atoi(emptyString) == s.atoi(emptyString));
	assert(atoi(whitespace) == s.atoi(whitespace));
	assert(atoi(nonIntChar) == s.atoi(nonIntChar));
	assert(atoi(startNonInt) == s.atoi(startNonInt));
	assert(atoi(a) == s.atoi(a));
	assert(atoi(leadingSpaceAndZeroWithGap) == s.atoi(leadingSpaceAndZeroWithGap));
}

int main(void) {
	Solution s;
	testValidInts();
	testWackyStringInput();
	cout << s.atoi("+141") << endl;
	cout << atoi("+141") << endl;
    return 0;
}