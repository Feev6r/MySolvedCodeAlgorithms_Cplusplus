#include <iostream>
#include <vector>

using namespace std;




int myAtoi(string s) {

    int i = 0;
    int sign = 1;
    long ans = 0;

    while (i < s.length() && s[i] == ' ') i++;

    if (s[i] == '-')
    {
        sign = -1;
        i++;
    }

    else if (s[i] == '+') i++;


    while (i < s.length())
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            ans = ans * 10 + (s[i] - '0');

            if (ans > INT_MAX && sign == -1)
                return INT_MIN;

            else if (ans > INT_MAX && sign == 1)
                return INT_MAX;

            i++;
        }
        else 
            return ans * sign;
    }
    return (ans * sign);

}


int myAtoi(string s) {

	int ans = 0;
	int sign = 1;

	for (int i = 0; i < s.length(); i++)
	{
		if (ans > INT_MAX / 10) {
			if(sign != -1) return INT_MAX;
			return INT_MIN;
		}


		if (s[i] != ' ') {

			if (i == 0 && !isdigit(s[i]) && (s[i] != '-' && s[i] != '+')) return 0;
			if (!isdigit(s[i + 1])) return (ans * 10 + s[i] - '0') * sign;


			if (s[i] == '-') {
				sign = -1;
				i++;
			}

			ans = ans * 10 + s[i] - '0';

		}

	}

	return ans * sign;
}

int main()
{
	cout << myAtoi("  42");
}

//123-32231-21321-123321-3213123-123123-21313-3123123-12312312-312321

//char b = '-';
//
//if (!isdigit(b) && b != '-') {
//	cout << "Si";
//}
//else {
//	cout << "No";
//}