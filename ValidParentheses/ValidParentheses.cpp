#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;


//My Solution, a little bit messy...
bool isValid(string s) {

	stack<int> stack;
	unordered_map<char, char> map;
	map['('] = ')';	map['['] = ']'; map['{'] = '}';

	if (s.length() <= 1) return false;


	int n = s.length();
	for (int i = 0; i < n; i++)
	{
		if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
			stack.push(s[i]);
		}
		else{
			if (s[i] == map[stack.top()]) {
				stack.pop();
			}
			else return false;
		}
	}

	if (!stack.empty()) return false;
	return true;

}

//second solution:
bool isValid2(string s) {

	stack<char> st; // create an empty stack to store opening brackets
	
	for (char c : s) { // loop through each character in the string
	
		if (c == '(' || c == '{' || c == '[') { // if the character is an opening bracket
			st.push(c); // push it onto the stack
		}		
		else { // if the character is a closing bracket

			if (st.empty() || // if the stack is empty or 
				(c == ')' && st.top() != '(') || // the closing bracket doesn't match the corresponding opening bracket at the top of the stack
				(c == '}' && st.top() != '{') ||
				(c == ']' && st.top() != '[')) {
				return false; // the string is not valid, so return false
			}
			st.pop(); // otherwise, pop the opening bracket from the stack
		}
	}

	return st.empty(); // if the stack is empty, all opening brackets have been matched with their corresponding closing brackets,
	// so the string is valid, otherwise, there are unmatched opening brackets, so return false
}



int main()
{
	isValid2("([])");
}

