#include <iostream>
#include <stack>

using namespace std;

//My messy solution haha
bool backspaceCompare(string s, string t) {

	stack<char> stk;
	string a;
	string b;

	int i = s.size() - 1;
	while (i >= 0)
	{

		if (s[i] == '#') stk.push(s[i]);
		else if (stk.empty()) a += s[i];

		if (s[i] != '#' && !stk.empty()) stk.pop();

		i--;
	}

	i = t.size() - 1;
	while (!stk.empty()) {
		stk.pop();
	}

	while (i >= 0)
	{
		if (t[i] == '#') stk.push(t[i]);
		else if (stk.empty()) b += t[i];

		if (t[i] != '#' && !stk.empty()) stk.pop();
		i--;
	}

	return b == a;
}

//Time: O(n) Space: O(1) Solution. 
bool backspaceCompare2(string S, string T) {

	int i = S.length() - 1, j = T.length() - 1;

	int skipS = 0, skipT = 0;

	while (i >= 0 || j >= 0) { // While there may be chars in build(S) or build(T)
		// Find position of next possible char in build(S)
		while (i >= 0) {
			if (S[i] == '#') {
				skipS++; i--;
			}
			else if (skipS > 0) {
				skipS--; i--;
			}
			else {
				break;
			}
		}
		// Find position of next possible char in build(T)
		while (j >= 0) {
			if (T[j] == '#') {
				skipT++; j--;
			}
			else if (skipT > 0) {
				skipT--; j--;
			}
			else {
				break;
			}
		}
		// If two actual characters are different
		if (i >= 0 && j >= 0 && S[i] != T[j])
			return false;
		// If expecting to compare char vs nothing
		if ((i >= 0) != (j >= 0))
			return false;
		i--; j--;
	}
	return true;
}
int main()
{
	cout << backspaceCompare("ab##", "c#d#");
}

