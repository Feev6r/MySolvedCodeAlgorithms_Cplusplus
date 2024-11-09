#include <iostream>
#include <vector>

using namespace std;

//Messy solution by me (fernando del futuro dont struggle understanding this shit, is not worthy at all)
int search(vector<int>& nums, int start, int end) {

    if (start >= end) return start;

    int mid = (end - start) / 2 + start;

    if ((mid - 1 < 0 && nums[mid + 1] < nums[mid]) || (mid -1 >= 0 && nums[mid - 1] < nums[mid] && nums[mid] > nums[mid + 1])) {
        return mid;
    }
    
    if (mid - 1 < 0 || mid + 1 <= nums.size() -1 && nums[mid + 1] > nums[mid - 1]) return search(nums, mid + 1, end);
    else return search(nums, start, mid - 1);

}

int findPeakElement(vector<int>& nums) {

    if (nums.size() == 1) return 0;
    return search(nums, 0, nums.size() -1);
} 


//the real peak solution: (this is okay to understand)
int findPeakElement(vector<int>& nums) {
    int left = 0;
    int right = nums.size() - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] > nums[mid + 1]) {
            right = mid;
        }
        else {
            left = mid + 1;
        }
    }

    return left;
}

int main()
{
    vector<int> v = { 1,2,3,4,7 };
    vector<int> v2 = { 8,6,3,2,1 };
    vector<int> v3 = { 1,2 };
    findPeakElement(v3);
}



//(mid + 1 >= nums.size() - 1 && nums[mid - 1] < nums[mid]) ||
//    (mid - 1 <= 0 && nums[mid + 1] < nums[mid]) ||