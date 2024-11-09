#include <iostream>
#include <vector>

using namespace std;

int search(vector<int>& nums, int target) {

    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {

        int mid = (right - left) / 2 + left;

        if (nums[mid] == target) {
            return mid;
        }
        else if (nums[mid] > nums[left]) {
            if (target < nums[mid] && target >= nums[left]) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        else {
            if (target > nums[mid] && target <= nums[right]) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
    }
    return -1;

}

int main()
{
    vector<int> v = { 5,6,7,8,9,10,11,12,13,0,1,2,3,4 };
    search(v, 0);
}

