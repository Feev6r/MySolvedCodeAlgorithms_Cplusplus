#include <iostream>
#include <string>

using namespace std;


string reverseStringRec(string str) {

    if (str.length() <= 1) return str;

    return (reverseStringRec(str.substr(1))) + str[0];

}

//TIME = O(N^2) 
//SPACE = O(N)

string reverseStringTab(string str) {

    int strsSize = str.length();
    string result;

    for (int i = strsSize -1; i >= 0; i--)
    {
        result += str[i];
    }

    return result;

}

//TIME = O(N)
//SPACE = O(N)


int main()
{
    //cout << reverseStringRec("coderbyte") << endl;
    cout << reverseStringTab("coderbyte") << endl;
}
