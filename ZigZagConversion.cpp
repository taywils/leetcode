#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <cmath>

using namespace std;

class Solution
{
public:
	string convert(string s, int nRows)
	{
		string answer = "";
		if (0 == s.length() || nRows < 1)
		{
			return "";
		}
		else if (1 == nRows)
		{
			return s;
		}
		else
		{
			int colSize = ceil(s.length() / 2.0);
			vector< vector<char> > grid(nRows, vector<char>(colSize));

			int r = 0, c = 0;
			bool up = false;
			for (char l : s)
			{
				if (up)
				{
					grid[r--][c++] = l;
					if (r < 0)
					{
						up = false;
						r += 2;
						--c;
					}
					continue;
				}
				else
				{
					grid[r++][c] = l;
					if (r >= nRows)
					{
						r -= 2;
						++c;
						up = true;
					}
					continue;
				}
			}

			for (vector<char> row : grid)
			{
				for (char letter : row)
				{
					if ('\0' != letter)
					{
						answer += letter;
					}
				}
			}
		}
		return answer;
	}
};

int main()
{
	Solution s;
	assert("PAHNAPLSIIGYIR" == s.convert("PAYPALISHIRING", 3));
	assert("A" == s.convert("A", 1));
	assert("ABC" == s.convert("ABC", 1));
	return 0;
}
