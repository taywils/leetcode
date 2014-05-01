#include <iostream>
#include <string>
#include <cassert>
#include <algorithm>

using namespace std;

class Solution {
public:
	bool isPalindrome(int x) {
		string xStr = to_string(x);
		int xStrLen = 0;

		if('-' == xStr[0]) {
			return false;
		} else {
			xStrLen = xStr.length();
		}

		if(1 == xStrLen) {
			return true;
		}

		string halfA = "";
		string halfB = "";

		if(xStrLen % 2 == 0) { // Even number of integers
			for(int i = 0; i < xStrLen; ++i) {
				if(i < xStrLen / 2) {
					halfA += xStr[i];
				} else {
					halfB += xStr[i];
				}
			}

			assert(xStr == (halfA + halfB));
		} else {
			char mid = xStr[xStrLen / 2];

			for(int i = 0; i < xStrLen; ++i) {
				if(xStrLen / 2 == i) {
					continue;
				}

				if(i < xStrLen / 2) {
					halfA += xStr[i];
				} else {
					halfB += xStr[i];
				}
			}

			assert(xStr == (halfA + mid + halfB));
		}

		std::reverse(halfB.begin(), halfB.end());

		if(halfA == halfB) {
			return true;
		} else {
			return false;
		}
	}
};

void tests() {
	Solution s;
	assert(false == s.isPalindrome(-121));
	assert(false == s.isPalindrome(4969831));

	assert(true == s.isPalindrome(0));
	assert(true == s.isPalindrome(121));
	assert(true == s.isPalindrome(6886));
	assert(true == s.isPalindrome(69696));
	assert(true == s.isPalindrome(999999));
	assert(true == s.isPalindrome(1010101));
}

int main() {
	tests();
}
