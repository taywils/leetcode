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

class Solution {
public:
	vector< vector<int> > answer;

	vector< vector<int> > threeSum(vector<int> &num) {
		if (num.empty() || num.size() < 3) {
			return this->answer;
		}

		set<int> lol;
		auto lolSize = num.size();
		for (unsigned int i = 0; i < num.size(); ++i) lol.insert(num[i]);
		num.assign(lol.begin(), lol.end());

		if (num.size() < 3) {
			if (num.at(num.size() - 1) == 0) {
				vector<int> temp(3);
				this->newAnswer(temp);
			}
			return this->answer;
		}

		sort(num.begin(), num.end());

		for (int i = 0; i < num.size() - 2; ++i) {
			int j = i + 1;
			int k = i + 2;
			
			while (j < num.size() - 1) {
				if (k == num.size()) {
					j++;
					k = j + 1;
					continue;
				}
				if ((num.at(i) + num.at(j) + num.at(k)) == 0) {
					vector<int> temp = { num.at(i), num.at(j), num.at(k) };
					this->newAnswer(temp);
				}
				++k;
			}
		}

		return this->answer;
	}

private:
	void newAnswer(vector<int> triple) {
		auto notFound = (find(this->answer.begin(), this->answer.end(), triple) == this->answer.end());
		if (notFound)
			this->answer.push_back(triple);
	}
};

int main() {
	Solution s;
	vector<int> t1 = { 0, 0, 0, 0 };
	vector<int> t2 = { 3, 0, -2, -1, 1, 2 };
	vector<int> t3 = { 1, 1, -2 };
	auto answer = s.threeSum(t3);
	return 0;
}