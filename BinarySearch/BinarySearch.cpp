#include <iostream>
#include <cmath>


bool binarySearch(int arr[], int start, int end, int target) {
    
    std::cout << start << " - " << end << std::endl;

    if (start > end) return false;
    
    int midIndex = round((start + end) / 2);

    if (arr[midIndex] == target) return true;

    if (arr[midIndex] > target) return binarySearch(arr, start, midIndex - 1, target);
    else return binarySearch(arr, midIndex + 1, end, target);
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

