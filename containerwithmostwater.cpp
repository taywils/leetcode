/*
Given n non-negative integers a1, a2, ..., an, where each represents
a point at coordinate (i, ai). n vertical lines are drawn such that the two
endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together
with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container.
*/

#include <vector>
#include <iostream>
#include <cassert>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
		if (height.size() > 1) {
			int front = 0;
			int back = height.size() - 1;
			return this->calculate(front, back, height);
		}
		else {
			return 0;
		}
    }

private:
	int calculate(int ft, int bk, vector<int> &height) {
		int ma = 0;
		int maNew = ma;
		while (ft < bk) {
			int base = bk - ft;
			int h1 = height.at(ft);
			int h2 = height.at(bk);

			if (h2 == h1) {
				maNew = base * h1;
				++ft;
				--bk;
			}
			else if (h2 > h1) {
				maNew = min(h2, h1) * base;
				++ft;
			}
			else {
				maNew = min(h2, h1) * base;
				--bk;
			}
			ma = max(maNew, ma);
		}

		return ma;
	}
};

/*
int main(int argc, char** argv) {
	Solution s = Solution();

	vector<int> t1 = vector<int>();
	vector<int> t2 = { 2 };
	assert(0 == s.maxArea(t1));
	assert(0 == s.maxArea(t2));

	vector<int> t3 = { 0, 1 };
	assert(0 == s.maxArea(t3));

	vector<int> t4 = { 1, 1 };
	assert(1 == s.maxArea(t4));

	vector<int> t5 = { 2, 1 };
	cout << s.maxArea(t5) << endl;
	assert(1 == s.maxArea(t5));

	vector<int> t6 = { 2, 1, 10, 5, 5, 5, 20 };
	cout << s.maxArea(t6) << endl;
	assert(40 == s.maxArea(t6));

	return EXIT_SUCCESS;
}
*/