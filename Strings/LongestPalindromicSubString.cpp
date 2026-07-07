#include <iostream>
#include <string>
#include <chrono>

/**
 * @brief Class to find the longest palindromic substring in a given string.
 */
class Solution {
  private:
    /**
     * @brief Expands around a given center and returns the length of the palindrome.
     * @param str The original string.
     * @param left The left starting index of the center.
     * @param right The right starting index of the center.
     * @return The length of the longest palindrome found from this center.
     */
    int expandAroundCenter(const std::string& str, int left, int right) {
      while (left >= 0 && right < str.length() && str[left] == str[right]) {
        left--;
        right++;
      }

      return right - left - 1; 
    }

  public:
    /**
     * @brief Finds the longest palindromic substring in the given string.
     * @param s The input string.
     * @return The longest palindromic substring found in the input string.
     */
    std::string longestPalindrome(std::string s) {
      if (s.length() < 2) {
        return s;
      }

      int start = 0;
      int maxLength = 1;

      for (int i = 0; i < s.length(); i++) {
        int len1 = expandAroundCenter(s, i, i);
        int len2 = expandAroundCenter(s, i, i + 1);
        
        int currentMax = std::max(len1, len2);

        if (currentMax > maxLength) {
          maxLength = currentMax;
          start = i - (currentMax - 1) / 2; 
        }
      }
      
      return s.substr(start, maxLength);
    } 
};


/**
 * @brief Main function to test the longestPalindrome function.
 * @return int Exit status of the program.
 */
int main() {
    auto start = std::chrono::high_resolution_clock::now();
    Solution solution;
    std::string input = "babad";

    std::string result = solution.longestPalindrome(input);
    std::cout << "\nLongest palindromic substring: " << result << std::endl;
    
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Time taken by longestPalindrome: " << duration.count() << " microseconds" << std::endl;
    return 0;
}
