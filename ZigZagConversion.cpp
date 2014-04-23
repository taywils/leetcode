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
    vector< vector<string> > grid;
    if(0 == s.length() || nRows < 1) {
      return "";
    } else {
      for(int i = 0; i < nRows; ++i) {
        vector<string> row;
        grid.push_back(row);
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
