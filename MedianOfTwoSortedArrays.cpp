#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	double findMedianSortedArrays(int A[], int m, int B[], int n) {
		if (n == 0 && m == 0) {
			return 0.0;
		}
		double median = 0.0;
		vector<double> com(n + m);

		com = this->combine(A, m, B, n);

		if ((com.size() % 2) == 0) {
			unsigned long idx1 = (com.size() / 2.0) - 1;
			unsigned long idx2 = com.size() / 2.0;
			median = (com[idx1] + com[idx2]) / 2.0;
		}
		else {
			int idx = ceil(com.size() / 2.0) - 1;
			median = com[idx];
		}

		return median;
	}

	vector<double> combine(int A[], int m, int B[], int n) {
		vector<double> in;
		for (int i = 0; i < m; ++i) {
			in.push_back(A[i]);
		}
		for (int i = 0; i < n; ++i) {
			in.push_back(B[i]);
		}
		sort(in.begin(), in.end());
		return in;
	}
};