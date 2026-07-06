#include <iostream>
#include <vector>
#include <unordered_map>

/** 
 * @brief Finds two numbers in an array that add up to a target value.
 * @param nums The array of integers.
 * @param target The target sum.
 * @return A vector containing the indices of the two numbers that add up to the target.
 */
class Solution {
	public:
		// Function to find two numbers that add up to a target value
		std::vector<int> twoSum(std::vector<int>& nums, int target) {
			std::unordered_map<int, int> seenNumbers;
			int length = nums.size();

			// Iterate through the array to find the two numbers
			for (int i = 0; i < length; i++) {
					int currentNumber = nums[i];
					int requiredComplement = target - currentNumber;

					if (seenNumbers.find(requiredComplement) != seenNumbers.end()) {
							return {seenNumbers[requiredComplement], i};
					}
					seenNumbers[currentNumber] = i; 
			}
	
			return {};
		}
	};

// Test the function with example inputs
int main() {
	Solution solver;

	std::vector<int> testNums = {2, 7, 11, 15};
	int testTarget = 9;

	std::vector<int> result = solver.twoSum(testNums, testTarget);

	std::cout << std::endl;
	std::cout << "--- Test results ---" << std::endl;
	if (!result.empty()) {
			std::cout << "Indexes found: [" << result[0] << ", " << result[1] << "]" << std::endl;
			std::cout << "Test: " << testNums[result[0]] << " + " << testNums[result[1]] << " = " << testTarget << std::endl;
	} else {
			std::cout << "Not found" << std::endl;
	}

	return 0;
}