#include <iostream>
#include <stack>
#include <string>

using namespace std;


std::string decodeString2(const std::string& s) {
    stack<int> st;
    stack<string> st1;
    string aString;
    int n = 0;

    for (char c : s) {
        if (isdigit(c)) {
            n = n * 10 + (c - '0');
        }
        else if (c == '[') {
            st.push(n);
            n = 0;
            st1.push(aString);
            aString.clear();
        }
        else if (c == ']') {

            int k = st.top();
            st.pop();

            string temp = aString;

            aString = st1.top();
            st1.pop();

            while (k-- > 0) {
                aString += temp;
            }
        }
        else {
            aString += c;
        }
    }

    return aString;
}


//TOP SOLUTION
string decodeString3(const string& s, int& i) {
    string res;

    while (i < s.length() && s[i] != ']') {

        if (!isdigit(s[i]))
            res += s[i++];
        else {
            int n = 0;
            while (i < s.length() && isdigit(s[i]))
                n = n * 10 + s[i++] - '0';

            i++; // '['
            string t = decodeString3(s, i);
            i++; // ']'

            while (n-- > 0)
                res += t;
        }
    }

    return res;
}



int main()
{
    int a = 0;
	decodeString3("30[a2[c]b]e", a);
}

