#include <iostream>
#include <vector>

using namespace std;

int mySqrt(int x) {

    int l = 0;
    int r = x;

    while (l <= r) {

        int mid = l + (r - l) / 2;

        if (mid * mid == x) return mid;
        else if (mid * mid > x) {
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }

    }

    return r;
}

int main()
{
    std::cout << "Hello World!\n";
}
