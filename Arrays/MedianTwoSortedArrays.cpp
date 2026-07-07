#include <iostream>
#include <vector>
#include <climits>

/** 
 * @brief Finds the median of two sorted arrays.
 * @param nums1 The first sorted array.
 * @param nums2 The second sorted array.
 * @return The median of the two sorted arrays.
 */
class Solution {
  public:
    // Function to find the median of two sorted arrays
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
      if (nums1.size() > nums2.size()) {
        return findMedianSortedArrays(nums2, nums1);
      }

      // Lengths of the two arrays
      int x = nums1.size();
      int y = nums2.size();
      int low = 0;
      int high = x;

      // Binary search to find the correct partition
      while (low <= high) {
        int partitionX = (low + high) / 2;
        int partitionY = (x + y + 1) / 2 - partitionX;

        int maxLeftX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
        int minRightX = (partitionX == x) ? INT_MAX : nums1[partitionX];

        int maxLeftY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
        int minRightY = (partitionY == y) ? INT_MAX : nums2[partitionY];

        // Check if we have found the correct partition
        if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
          if ((x + y) % 2 == 0) {
            return (std::max(maxLeftX, maxLeftY) + std::min(minRightX, minRightY)) / 2.0;
          } else {
            return std::max(maxLeftX, maxLeftY);
          }
        } else if (maxLeftX > minRightY) {
          high = partitionX - 1;
        } else {
          low = partitionX + 1;
        }
      }
      
      throw std::invalid_argument("Input arrays are not sorted.");
    }
};

// Test the function with example inputs
int main() {
  Solution solution;
  std::vector<int> nums1 = {1, 3};
  std::vector<int> nums2 = {2};

  double median = solution.findMedianSortedArrays(nums1, nums2);
  std::cout << "\nMedian of the two sorted arrays: " << median << std::endl;

  return 0;
}