#include <string>
#include <iostream>
#include <cassert>

using namespace std;

class Solution {
public:
	bool isMatch(const char *s, const char *p) {

	}
};

void tests() {
	Solution s;

	assert(s.isMatch("aa", "a") == false);
	assert(s.isMatch("aa", "aa") == true);
	assert(s.isMatch("aaa", "aa") == false);
	assert(s.isMatch("aa", "a*") == true);
	assert(s.isMatch("aa", ".*") == true);
	assert(s.isMatch("ab", ".*") == true);
	assert(s.isMatch("aab", "c*a*b") == true);
}

int main() {
	tests();
}