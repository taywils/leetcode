/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 
Find all unique triplets in the array which gives the sum of zero.

Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets.

For example, given array S = {-1 0 1 2 -1 -4},

A solution set is:
(-1, 0, 1)
(-1, -1, 2)
*/
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

// Correct but too slow.
class Solution {
public:
	set< vector<int> > answer;

	vector< vector<int> > threeSum(vector<int> &num) {
		sort(num.begin(), num.end());
		for (unsigned int i = 0; i < num.size(); ++i) {
			for (unsigned int j = i + 1; j < num.size(); ++j) {
				unsigned int k = j + 1;
				while (k < num.size()) {
					if ((num.at(i) + num.at(j) + num.at(k)) == 0) {
						vector<int> temp = { num.at(i), num.at(j), num.at(k) };
						this->newAnswer(temp);
					}
					++k;
				}
			}
		}
		return this->answerSetToVec();
	}

	void newAnswer(vector<int> triple) {
		this->answer.insert(triple);
	}

	vector< vector<int> > answerSetToVec() {
		vector< vector<int> > vecAnswer;
		for (auto elem : answer) {
			vecAnswer.push_back(elem);
		}

		return vecAnswer;
	}
};

int main() {
	Solution s;
	vector<int> t1 = { -1, 0, 1, 2, -1, -4 };
	auto answer = s.threeSum(t1);
	return 0;
}