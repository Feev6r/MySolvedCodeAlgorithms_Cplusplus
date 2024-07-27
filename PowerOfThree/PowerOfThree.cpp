#include <iostream>
#include <vector>

using namespace std;

//Olog3(n)
bool isPowerOfThree(int n) {
    if (n <= 1) return n == 1;
    return n % 3 == 0 && isPowerOfThree(n / 3);
}
//O(1)
bool isPowerOfThree2(int n) {
    return n > 0 && (1162261467 % n == 0);
}


int main()
{
  cout << isPowerOfThree(0);
}

