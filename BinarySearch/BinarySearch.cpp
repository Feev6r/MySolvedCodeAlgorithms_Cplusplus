#include <iostream>
#include <cmath>
#include <vector>


using namespace std;

//RECURSIVE APPROACH:
bool binarySearch(int arr[], int start, int end, int target) {
    
    std::cout << start << " - " << end << std::endl;

    if (start > end) return false;
    
    int midIndex = round((start + end) / 2);

    if (arr[midIndex] == target) return true;

    if (target < arr[midIndex]) return binarySearch(arr, start, midIndex - 1, target);
    else return binarySearch(arr, midIndex + 1, end, target);
}


//ITERATIVE APPROACH: 
int binarySearch2(vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        }
        else if (target > arr[mid]) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return -1; // Target not found
}

int main()
{
    int a[1024];

    for (int i = 0; i < 1024; i++)
    {
        a[i] = i;
    }

    int start = 0;
    int end = sizeof(a) / sizeof(int) - 1;
    int target = 8;



    std::cout << binarySearch(a, start, end, target);
}

