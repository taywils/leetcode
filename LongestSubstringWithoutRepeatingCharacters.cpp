#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		auto cs = s.c_str();
		int maxlen = 0;
		int head = 0;
		int tail = 0;
		auto slen = s.length();
		bool set[256] = { false };
		while (tail < slen) {
			if (set[cs[tail]]) {
				maxlen = max(maxlen, tail - head);
				while (cs[head] != cs[tail]) {
					set[cs[head]] = false;
					head++;
				}
				head++;
				tail++;
			}
			else {
				set[cs[tail]] = true;
				tail++;
			}
		}
		return max(maxlen, (int)slen - head);
	}
};