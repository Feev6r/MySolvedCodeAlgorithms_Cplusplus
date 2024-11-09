#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <numeric>

using namespace std;


//NOTE: WHEN YOU NEED TO SEE PREVIEW DATA IS BETTER USING AN ARRAY (VECTOR) THAN A STACK

//NASTY SOLUTION, my solution
int calPoints(vector<string>& operations) {

    stack<int> scoreStack;
    int previousScore = 0;
    int total = 0;
    for (string& s : operations) {

        if (isdigit(s[0]) || s[0] == '-') {
            if (!scoreStack.empty()) previousScore = scoreStack.top(); 

            scoreStack.push(stoi(s));
            total += scoreStack.top();
        }
        else if (s[0] == '+') {
            int prevTemp = scoreStack.top();
            scoreStack.push(previousScore + scoreStack.top()); 
            if (!scoreStack.empty()) previousScore = prevTemp;

            total += scoreStack.top();
        }
        else if (s[0] == 'D') {
            if (!scoreStack.empty()) previousScore = scoreStack.top();

            scoreStack.push(scoreStack.top() * 2); 
            total += scoreStack.top();
        }
        else if (s[0] == 'C') {
            total -= scoreStack.top();
            scoreStack.pop();

            if (scoreStack.size() >= 2) {
                int temp = scoreStack.top();
                scoreStack.pop();
                previousScore = scoreStack.top(); 
                scoreStack.push(temp);
            }
            else {
                previousScore = 0;
            }
        }
    }
    return total;

}

//NOTE: WHEN YOU NEED TO SEE PREVIEW DATA IS BETTER USING AN ARRAY (VECTOR) THAN A STACK


//Best solution
int calPoints(vector<string>& operations) {
    vector<int> a;

    for (const string& op : operations) {
        if (op == "+") {
            a.push_back(a[a.size() - 1] + a[a.size() - 2]);
        }
        else if (op == "D")
        {
            a.push_back(2 * a.back());
        }
        else if (op == "C") {
            a.pop_back();
        }
        else {
            a.push_back(stoi(op));
        }
    }
    return accumulate(a.begin(), a.end(), 0);
}


int main()
{
    vector<string> v = { "5","-2","4","C","D","9","+","+" };
    calPoints(v);
}
