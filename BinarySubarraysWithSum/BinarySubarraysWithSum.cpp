#include <iostream>
#include <vector>

using namespace std;


//INTERESTING SOLUTION BUT A BIT DIFFICULT TO UNDERSTAND AT THE BEGINING.
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return slidingWindowAtMost(nums, goal) - slidingWindowAtMost(nums, goal - 1);
    }
private:
    // Helper function to count the number of subarrays with sum at most the given goal
    int slidingWindowAtMost(vector<int>& nums, int goal) {
        int start = 0, currentSum = 0, totalCount = 0;

        // Iterate through the array using a sliding window approach
        for (int end = 0; end < nums.size(); end++) {
            currentSum += nums[end];

            // Adjust the window by moving the start pointer to the right
            // until the sum becomes less than or equal to the goal
            while (start <= end && currentSum > goal) {
                currentSum -= nums[start++];
            }

            // Update the total count by adding the length of the current subarray
            totalCount += end - start + 1;
        }
        return totalCount;
    }
};

//BEST INTUITIVE SOLUTION:
int numSubarraysWithSum(vector<int>& nums, int goal) {
    int start = 0;
    int prefixZeros = 0;
    int currentSum = 0;
    int totalCount = 0;

    // Loop through the array using end pointer
    for (int end = 0; end < nums.size(); ++end) {
        // Add current element to the sum
        currentSum += nums[end];

        // Slide the window while condition is met
        while (start < end && (nums[start] == 0 || currentSum > goal)) {
            if (nums[start] == 1) {
                prefixZeros = 0;
            }
            else {
                prefixZeros += 1;
            }

            currentSum -= nums[start];
            start += 1;
        }

        // Count subarrays when window sum matches the goal
        if (currentSum == goal) {
            totalCount += 1 + prefixZeros;
        }
    }

    return totalCount;
}

int main()
{
	std::cout << "Hello World!\n";
}
