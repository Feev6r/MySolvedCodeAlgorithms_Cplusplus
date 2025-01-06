#include <iostream>
#include <vector>

using namespace std;

int hIndex(vector<int>& citations) {

    int n = citations.size();

    int left = 0;
    int right = n - 1;

    int mid;

    while (left <= right) {

        mid = left + (right - left) / 2;
        
        if (citations[mid] >= (n - mid)) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    return n - left;
}


int main()
{
    vector<int> v = { 1,2,100 };
    hIndex(v);
}

