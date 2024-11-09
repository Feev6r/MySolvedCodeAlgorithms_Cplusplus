#include <iostream>
#include <vector>

using namespace std;


int search(vector<int>& nums, int start, int end, int target) {

    if (start >= end) {
    
        if (target > nums[start]) return start + 1;
        else return start;
    } 

    int midIndex = round((start + end) / 2);

    if (nums[midIndex] == target) return midIndex;

    if (target < nums[midIndex]) return search(nums, start, midIndex - 1, target);
    else return search(nums, midIndex + 1, end, target);
}

int searchInsert(vector<int>& nums, int target) {
     return search(nums, 0, nums.size() - 1, target);
}


int main()
{
    std::cout << "Hello World!\n";
}
