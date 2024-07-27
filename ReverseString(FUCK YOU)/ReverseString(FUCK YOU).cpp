#include <iostream>
#include <vector>
//#include <algorithm>


using namespace std;

void reverseString(vector<char>& s) {


	int i = 0;
	int j = s.size() - 1;
	
	while (j > i)
	{
		char temp = s[i];

		s[i] = s[j];
		s[j] = temp;
		i++;
		j--;
	}

}


int main()
{
	cout << 1 % 10;
}

