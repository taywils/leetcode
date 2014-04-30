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
	int atoi(const char *str) {
		int myInt = 0;
		int myDigit = 0;
		string intMaxStr = to_string(INT_MAX);
		string intMinStr = to_string(INT_MIN);

		str = this->prepareStr(str);

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

	const char* prepareStr(const char* cStr) {
		string cppStr(cStr);
		if(cppStr.length() == 0) {
			return { "" };
		}
		int idx = 0;
		// Remove leading whitespace
		for(auto s : cppStr) {
			if(' ' == s) {
				++idx;
			} else {
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
			if(isalpha(s) && s != '-') {
				break;
			} else {
				++idx;
			}
		}
		cppStr = cppStr.substr(0, idx);

		return cppStr.c_str();
	}
};

void testValidInts() {
	std::random_device rd;
	std::mt19937 mt{ rd() };
	std::uniform_int_distribution<int> dist{ INT_MIN, INT_MAX };

	Solution solution;
	const int trials = 0;

	for (int i = 0; i < trials; ++i) {
		int randNum = dist(mt);
		string randNumStr = to_string(randNum);
		const char* randNumCStr = randNumStr.c_str();
		assert(atoi(randNumCStr) == solution.atoi(randNumCStr));
	}

	string largerThanMax{"2147483648"};
	string smallerThanMin{"-2147483648"};
	assert(INT_MAX == solution.atoi(largerThanMax.c_str()));
	assert(INT_MIN == solution.atoi(smallerThanMin.c_str()));
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
}

int main(void) {
	testValidInts();
	//testWackyStringInput();
    return 0;
}