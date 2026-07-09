#include <iostream>
#include <chrono>
#include <climits>

/**
 * @brief Class to reverse an integer.
 */
class Solution {
  public:
    int reverse(int x) {
      int reversed = 0;
      
      while (x != 0) {
        int digit = x % 10;
        x /= 10;

        if (reversed > INT_MAX / 10 || (reversed == INT_MAX / 10 && digit > 7)) {
          return 0;
        }

        if (reversed < INT_MIN / 10 || (reversed == INT_MIN / 10 && digit < -8)) {
          return 0;
        }
        
        reversed = reversed * 10 + digit;
      }
      return reversed;
    }
};

/**
 * @brief Main function to test the reverse function.
 * @return int Exit status of the program.
 */
int main() {
  auto start = std::chrono::high_resolution_clock::now();

  Solution solution;
  int x = -12345;

  int result = solution.reverse(x);
  std::cout << "\nReversed integer: " << result << std::endl;

  auto end = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
  std::cout << "Execution time: " << duration.count() << " microseconds" << std::endl;

  return 0;
}