#include <iostream>
#include <climits>
#include <string>
#include <cassert>
#include <algorithm>
#include <cstdlib>

using namespace std;

class Solution
{
public:
	int reverse(int x) 
	{
		bool negative = false;

		if (0 == x)
		{
			return 0;
		}

		if (x < 0) 
		{
			negative = true;
			x = abs(x);
		}

		string xStr = to_string(x);

		if ('0' == xStr[xStr.length() - 1])
		{
			for (int i = xStr.length() - 1; i > 0; i--)
			{
				auto s = xStr.at(i);
				if ('0' == s)
				{
					xStr.pop_back();
				}
				else
				{
					break;
				}
			}
		}

		// Naieve overflow detection
		if (xStr.length() == 10 && xStr.at(xStr.length() - 1) > '1')
		{
			auto a = xStr.at(xStr.length() - 1);
			return 0;
		}

		if (negative)
		{
			xStr += "-";
		}

		std::reverse(xStr.begin(), xStr.end());
		auto cStr = xStr.c_str();

		return atoi(cStr);
	}
};

/*
int main(void)
{
	Solution s;

	assert(0 == s.reverse(0));
	assert(0 == s.reverse(-0));
	assert(123 == s.reverse(321));
	assert(-123 == s.reverse(-321));
	assert(1 == s.reverse(100));
	assert(-321 == s.reverse(-12300));
	assert(0 == s.reverse(1000000003));
	assert(0 == s.reverse(-1000000002));
	assert(1000000002 == s.reverse(2000000001));

	return EXIT_SUCCESS;
}*/