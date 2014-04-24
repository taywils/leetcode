#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "prettyprint.hpp"

using namespace std;

class Solution {
public:
  string convert(string s, int nRows) {
    string answer = "";
    vector< vector<char> > grid;
    if(0 == s.length() || nRows < 1) {
      return "";
    } else {
      for(int i = 0; i < nRows; ++i) {
        vector<char> row;
        grid.push_back(row);
      }

      int r, c = 0;
      bool up = false;
      for(char l : s) {
        if(up) {
          grid[r--][c++] = l;
          if(r < 0) {
            up = false;
          }
          continue;
        } else {
          grid[r++][c] = l;
          if(r >= nRows) {
            r -= 2; 
            ++c; 
            up = true;
          }
          continue;
        }
      }

      cout << grid << endl;
    }
    return answer;
  }
};

int main() {
  Solution s;
  s.convert("PAYPALISHIRING", 3);
  return 0;
}
