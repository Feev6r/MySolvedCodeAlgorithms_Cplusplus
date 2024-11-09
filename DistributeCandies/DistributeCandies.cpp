#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

int distributeCandies(vector<int>& candyType) {

    unordered_map<int, int> mp;

    int n = candyType.size() / 2;
    int ans = 0;
    for (int i = 0; i < n * 2; i++)
    {
        if (!mp.count(candyType[i])) ans++;
        mp[candyType[i]];

    }

    return ans <= n ? ans : n ;

}

int distributeCandies(vector<int>& candyType) {
    set<int>st;
    for (int val : candyType) st.insert(val);
    return min(candyType.size() / 2, st.size());
}

int main()
{
    std::cout << "Hello World!\n";
}

