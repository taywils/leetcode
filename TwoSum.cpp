class Solution {
public:
  vector<int> twoSum(vector<int> &numbers, int target) {
    long s = numbers.size();
    vector<int> r(2);
    for(int i = 0; i < s; ++i) {
      for(int j = int(s - 1); j > i; --j) {
        if((numbers.at(i) + numbers.at(j)) == target) {
          r[0] = i + 1;
          r[1] = j + 1;
          return r;
        }
      }
    }
    return r;   
  }
};