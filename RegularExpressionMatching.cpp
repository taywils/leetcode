#include <string>
#include <iostream>
#include <cassert>
#include <regex>

using namespace std;

class Solution {
public:
	bool isMatch(const char *s, const char *p) {
		string str(s);
		string queryStr(p);
		regex query(queryStr);

		return regex_match(s, query);
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

//int main() {
//	tests();
//}