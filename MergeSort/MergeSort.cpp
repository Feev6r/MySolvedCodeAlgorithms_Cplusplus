#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> slice(std::vector<int>& arr, int X, int Y)
{

    // Starting and Ending iterators
    auto start = arr.begin() + X;
    auto end = arr.begin() + Y;

    // To store the sliced vector
    std::vector<int> result(Y - X );

    // Copy vector using copy function()
    copy(start, end, result.begin());

    // Return the final sliced vector
    return result;
}



int main()
{
    std::vector<int> v;
    v.push_back(1); //0
    v.push_back(2); //1 
    v.push_back(3); //2
    v.push_back(4); //3

    std::vector<int> d = slice(v, 1, 3);

    std::vector<int> vCopy(4);

    std::copy(v.begin(), v.begin() + 4, vCopy.begin());


    for (int num: d)
    {
        std::cout << num << " ";
    }
}

