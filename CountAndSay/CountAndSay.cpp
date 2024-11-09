#include <iostream>
#include <vector>
#include <string>

using namespace std;

string solve(int n)
{
    if (n == 1) return "1";

    string prev = solve(n -1);
    string reform;

    int j = 0;
    int i = 0;

    int n = prev.size();

    while (i < n && j < n)
    {
        char temp = prev[i];

        while (i < n && temp == prev[i])
        {
            i++;
        }

        reform += to_string(i - j) + temp;
        j = i;
    }

    return reform;
}

string countAndSay(int n) {

    return solve(n);
}


int main()
{



}
