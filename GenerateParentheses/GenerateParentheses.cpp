#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string s;
        dfs(0, 0, s, n, res);
        return res;
    }

private:
    void dfs(int openP, int closeP, string& s, int& n, vector<string>& res) {
        if (s.size() == n * 2) {
            res.push_back(s);
            return;
        }

        if (openP < n) {
            s.push_back('(');
            dfs(openP + 1, closeP, s, n, res);
            s.pop_back();
        }

        if (closeP < openP) {
            s.push_back(')');
            dfs(openP, closeP + 1, s, n, res);
            s.pop_back();
        }
    }
};

int main()
{
	std::cout << "Hello World!\n";
}
