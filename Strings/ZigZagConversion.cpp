#include <iostream>
#include <string>

class Solution {
  public:
    std::string convert(std::string s, int numRows) {
      if (numRows == 1 || numRows >= s.length()) {
        return s;
      }

      std::string result;
      int cycleLen = 2 * numRows - 2;

      for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j + i < s.length(); j += cycleLen) {
          result += s[j + i];
          if (i != 0 && i != numRows - 1 && j + cycleLen - i < s.length()) {
            result += s[j + cycleLen - i];
          }
        }
      }

      return result;
    }
};

int main() {
  Solution solution;
  std::string s = "PAYPALISHIRING";
  int numRows = 3;

  std::string result = solution.convert(s, numRows);
  std::cout << "\nConverted string: " << result << std::endl;

  return 0;
}