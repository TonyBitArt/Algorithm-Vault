#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>

class Solution {
	public:
	int lengthOfLongestSubstring (std::string s) {
		std::unordered_set<char> charSet;
		int left = 0, right = 0, maxLength = 0;
		
		// Iterate through the string using a sliding window approach
		while (right < s.length()) {
			if (charSet.find(s[right]) == charSet.end()) {
				charSet.insert(s[right]);
				maxLength = std::max(maxLength, right - left + 1);
				right++;
			} else {
					charSet.erase(s[left]);
					left++;
			}
		}

		return maxLength;
	}
};

// Test the function with example inputs
int main() {
    Solution solution;
    std::string input = "abcabcbb";
    int result = solution.lengthOfLongestSubstring(input);
    std::cout << "\nLength of the longest substring without repeating characters: " << result << std::endl;
    return 0;
}