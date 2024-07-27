#include <iostream>


using namespace std;

bool isBadVersion(int version) {
    if (version >= 4) return true;
    else return false;
}

int firstBadVersion(int n) {

    if (!isBadVersion(n)) return n + 1;

    return firstBadVersion(n - 1);

}


int firstBadVersion2(int n) {
    int st = 1;
    int en = n;
    int ans = n;

    while (st <= en) {
        int mid = st + (en - st) / 2;

        if (isBadVersion(mid) == true) {
            ans = mid;
            en = mid - 1;
        }
        else {
            st = mid + 1;
        }
    }
    return ans;
}


int firstBadVersion3(int n) {

    int start = 0, end = n;

    while (end - start > 1) {

        int mid = start + (end - start) / 2;

        if (isBadVersion(mid)) end = mid;
        else  start = mid;
    }
    return end;
}

int main()
{
    cout <<firstBadVersion3(5);
}

