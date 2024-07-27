#include <iostream>
#include <vector>

using namespace std;

//good solution
bool isPalindrome2(string s) {

	int n = s.size();
	int left = 0;
	int right = n - 1;

	while (left < right) {

		if (!isalnum(s[left])) {
			left++;
		}
		else if (!isalnum(s[right])) {
			right--;
		}
		else if (tolower(s[left]) != tolower(s[right])) {
			return false;
		}
		else {
			left++;
			right--;
		}
	}
	return true;
}

//my solution
bool isPalindrome(string s) {


	int i = 0;
	int j = s.length() - 1;
	
	while (j > i)
	{
		
		if (!std::isalnum(static_cast<unsigned char>(s[i])) || s[i] == ' ') {
			i++;
			continue;
		}
		if (!std::isalnum(static_cast<unsigned char>(s[j])) || s[j] == ' ') {
			j--;
			continue;
		}

		if (s[i] >= 'A' && s[i] <= 'Z' && s[j] >= 'A' && s[j] <= 'Z') {
			if (s[i] + ('a' - 'A') != s[j] + ('a' - 'A')) return false;
		}
		else if(s[i] >= 'A' && s[i] <= 'Z') {
			if (s[i] + ('a' - 'A') != s[j]) return false;
		}
		else if(s[j] >= 'A' && s[j] <= 'Z') {
			if (s[i] != s[j] + ('a' - 'A')) return false;
		}
		else if (s[i] != s[j]) return false;

		i++;
		j--;
	}

	return true;

}

int main()
{
	cout << boolalpha << isPalindrome("A man, a plan, a canal: Panama");
}
//
//char c = 'a';
//char d = 'A';
//
//int b = c + ('a' - 'A');
//int e = d + ('a' - 'A');
//
//
//if (b == e) {
//	cout << "Si";
//}
//else {
//	cout << "No";
//
//}