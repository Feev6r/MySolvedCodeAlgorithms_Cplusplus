#include <iostream>
#include <vector>

using namespace std;
 
int removeDuplicates(vector<int>& nums) {

    int i = 0;

    for (int n : nums) {
        if (i < 2 || n > nums[i - 2])
            nums[i++] = n;
    }

    return i;
}


int main()
{
    vector<int> v = { 1,1,1,2,2,3 };
    removeDuplicates(v);
}
