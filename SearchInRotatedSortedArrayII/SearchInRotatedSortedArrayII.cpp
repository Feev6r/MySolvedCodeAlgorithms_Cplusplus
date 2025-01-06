#include <iostream>
#include <vector>

using namespace std;

//MY HUMBLE SOLUTION:
bool binarySearch(vector<int>& nums, int left, int right, int target) {

    if (left > right) return false;

    int mid = left + (right - left) /2;

    if (nums[mid] == target) {
        return true;
    }
    else if (nums[left] == nums[right]) {
        return binarySearch(nums, left, mid - 1, target) || binarySearch(nums, mid + 1, right, target);
    }
    else if (nums[mid] >= nums[left]) {

        if (target >= nums[left] && target < nums[mid]) {
            return binarySearch(nums, left, mid - 1, target);
        }
        else {
            return binarySearch(nums, mid + 1, right, target);
        }
    }
    else {
        if (target <= nums[right] && target > nums[mid]) {
            return binarySearch(nums, mid + 1, right, target);
        }
        else {
            return binarySearch(nums, left, mid - 1, target);
        }
    }

}


bool search(vector<int>& nums, int target) {

    return binarySearch(nums, 0, nums.size() - 1, target);
}


//BINARY SEARCH - ITERATIVE SOLUTION - BEST SOLUTION:
bool search2(vector<int>& nums, int target) {
    int l = 0;
    int r = nums.size() - 1;

    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        if (nums[mid] == target) return true;

        // with duplicates we can have this contdition, just update left & right
        if ((nums[l] == nums[mid]) && (nums[r] == nums[mid]))
        {
            l++;
            r--;
        }
        // first half
        // first half is in order
        else if (nums[l] <= nums[mid])
        {
            // target is in first  half
            if ((nums[l] <= target) && (nums[mid] > target))
                r = mid - 1;
            else
                l = mid + 1;
        }
        // second half
        // second half is order
        // target is in second half
        else
        {
            if ((nums[mid] < target) && (nums[r] >= target))
                l = mid + 1;
            else
                r = mid - 1;
        }
    }
    return false;
}
int main()
{
    vector<int> v = { 1,0,1,1,1 };
    search(v, 0);
}
