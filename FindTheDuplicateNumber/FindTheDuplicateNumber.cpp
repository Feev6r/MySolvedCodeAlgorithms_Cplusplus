#include <iostream>
#include <vector>

using namespace std;


int findDuplicate(vector<int>& nums) {
    int slow = nums[0];
    int fast = nums[0];

    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);

    fast = nums[0];

    while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    
    }
    return fast;
}

//BINARY SEARCH APPROACH
int findDuplicate(vector<int>& nums) {
    int left = 1;
    int right = nums.size() - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;
        int count = 0;

        // Count the numbers less than or equal to mid
        for (int num : nums) {
            if (num <= mid) {
                count++;
            }
        }

        // If count is greater than mid, the duplicate lies in the left half
        if (count > mid) {
            right = mid;
        }
        else { // Otherwise, it lies in the right half
            left = mid + 1;
        }
    }

    return left;
}

int main()
{
    std::cout << "Hello World!\n";
}

