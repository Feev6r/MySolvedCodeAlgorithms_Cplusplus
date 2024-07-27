#include <iostream>

using namespace std;


int fac(int n) {

    if (n == 1) return 1;

    return n * fac(n - 1);
}

//BIG O:

//Time O(n)
//Space O(n)

int main()
{
    std::cout << fac(6) << endl;
}
