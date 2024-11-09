#include <iostream>
#include <unordered_map>

using namespace std;

//My non-viable messy solution haha
bool isHappy(int n) {
    
    unordered_map<int, int> digits;
    unordered_map<int, int> trackResult;

    int t = 0;

    while (n > 1) {

        while (n > 1) {

            digits[n % 10]++;
            n /= 10;
        }
        digits[n]++;

        for (auto& m : digits) {

            while (m.second) {
                t += m.first * m.first;
                m.second--;
            }
        }
        digits.clear();
    
        if (trackResult.count(t)) return false;
        trackResult[t];

        n = t;
        t = 0;
    }

    return true;

}

//Expected solution
bool isHappy(int n) {
    if (n == 1) return true;

    int s = 0;

    while (n > 1) {

        while (n > 0) {

            int m = n % 10;
            s += m * m;
            n /= 10;
        }

        if (s == 1) {
            return true;
        }

        n = s;
        s = 0;

        if (n == 4) {
            return false;
        }
    }
    return false;
}

//Approach
//Initialize Sum Calculation : We calculate the sum of the squares of the digits of n.If the sum equals 1, then n is a happy number.
//
//Cycle Detection : If the sum becomes 4, it indicates that the number is entering a known cycle of unhappy numbers(this is a characteristic of the problem), so we return false.
//
//Iterate Until Result : We continue the process of summing the squares of the digits until either we reach 1 (indicating that n is happy) or detect a cycle(where n == 4), meaning the number is unhappy.

int main()
{
    cout << isHappy(121);
}

