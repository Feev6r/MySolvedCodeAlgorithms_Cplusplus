#include <iostream>
#include <vector>
#include <regex>

using namespace std;

std::string longestPalindromeM(std::string s) {
	if (s.length() <= 1) {
		return s;
	}

	int maxLen = 1;
	std::string maxStr = s.substr(0, 1);
	s = "#" + std::regex_replace(s, std::regex(""), "#") + "#";
	std::vector<int> dp(s.length(), 0);
	int center = 0;
	int right = 0;

	for (int i = 0; i < s.length(); ++i) {
		if (i < right) {
			dp[i] = std::min(right - i, dp[2 * center - i]);
		}

		while (i - dp[i] - 1 >= 0 && i + dp[i] + 1 < s.length() && s[i - dp[i] - 1] == s[i + dp[i] + 1]) {
			dp[i]++;
		}

		if (i + dp[i] > right) {
			center = i;
			right = i + dp[i];
		}

		if (dp[i] > maxLen) {
			maxLen = dp[i];
			maxStr = s.substr(i - dp[i], 2 * dp[i] + 1);
			maxStr.erase(std::remove(maxStr.begin(), maxStr.end(), '#'), maxStr.end());
		}
	}

	return maxStr;
}



bool isPalindrome(const std::string& str) {
	int left = 0;
	int right = str.length() - 1;

	while (left < right) {
		if (str[left] != str[right]) {
			return false;
		}
		++left;
		--right;
	}

	return true;
}


std::string longestPalindromeB(std::string s) {

	if (s.length() <= 1) {
		return s;
	}


	int max_len = 1;
	std::string max_str = s.substr(0, 1);

	for (int i = 0; i < s.length(); ++i) {

		for (int j = i + max_len; j <= s.length(); ++j) { //start with max_len so would be 1, just when i gets updated
		
			if (j - i > max_len && isPalindrome(s.substr(i, j - i))) { //(i, (j - i)) is basically right to left
			
				max_len = j - i;
				max_str = s.substr(i, j - i);
			}
		}
	}

	return max_str;
}
//babad
//abbad

//why it uses j - i, this is because this method uses brute force, so in this context is where it start, so is like the right pointer and j the "left" 

//di di di di di di di digital animal freaky folks







std::string longestPalindromeROUNDED(std::string s) {

	if (s.length() <= 1) {
		return s;
	}

	auto expand_from_center = [&](int left, int right) {
		while (left >= 0 && right < s.length() && s[left] == s[right]) {
			left--;
			right++;
		}
		return s.substr(left + 1, right - left - 1);
	};

	std::string max_str = s.substr(0, 1);

	for (int i = 0; i < s.length() - 1; i++) {
		std::string odd = expand_from_center(i, i);
		std::string even = expand_from_center(i, i + 1);

		if (odd.length() > max_str.length()) {
			max_str = odd;
		}
		if (even.length() > max_str.length()) {
			max_str = even;
		}
	}

	return max_str;
}

//bab

//Time: O(n^2)
//Space: O(1)

//study the algorithm here:
//----------------------

//[odd]
//
//i = 0
//
//exfc(0, 0)
//
//left--
//right++
//
//- 1, 1
//
//substr(-1 + 1, 1 - (-1 - 1)) = 0, 1
//b
//
//
//
//[even]
//
//i = 0
//
//exfc(0, 1)
//
//0, 1
//
//substr(0 + 1, 1 - 0 - 1) = 1, 0)
//""
//
//
//
//
//[odd]
//
//i = 1
//
//exfc(1, 1)
//
//left--
//right++
//
//0, 2
//
//left--
//right++
//
//- 1, 3
//
//substr(-1 + 1, 3 - (-1 - 1)) = 0, 3 //en left devolvemos 1 cuando no son iguales y right
//bab
//
//
//
//[even]
//
//i = 1
//
//exfc(1, 2)
//
//
//substr(1 + 1, 2 - 1 - 1) = 2, 0)
//""
//
//
//
//[odd]
//xhbabdf
//
//i = 3
//
//exfc(3, 3)
//
//left--
//right++
//
//2, 4
//
//left--
//right++
//
//1, 5
//
//substr(1 + 1, 5 - 1 - 1)) = 2, 3
//bab
//
//
//
//
//[odd]
//axhbabdfu
//
//i = 4
//
//exfc(4, 4)
//
//left--
//right++
//
//3, 5
//
//left--
//right++
//
//2, 6
//
//substr(2 + 1, 6 - 2 - 1)) = 3, 3
//bab
//
//
////why we substract or add numbers like this: s.substr(left + 1, right - left - 1);
////ex, x are ramdom letter that dont change or make the polindrome aba bigger:
//
////xx aba xx
////01 234 56
//
////if we're finish at index 1,5, we need to get back cuz x,x are different
////to do that we substract to left +1 to be at index 2 
////and we do something similar with rigth
////we are at index 5 so we substract left and -1 to right
////why left? beacuse
//5 - 1 - 1) = 3
//
//
//
//[even]
//xhbbbdf
//0123456
//
//i = 3
//
//exfc(3, 3 + 1) 3, 4
//
//
//left--
//right++
//
//2, 5
//
//
//substr(2 + 1, 5 - 2 - 1) = 3, 2)
//bb
//
//
//[even]
//xbbbbd
//012345
//
//i = 2
//
//exfc(2, 2 + 1) 2, 3
//
//
//left--
//right++
//
//1, 4
//
//left--
//right++
//
//0, 5
//
//substr(0 + 1, 5 - 0 - 1) = 1, 4)
//bbbb  Appointments to study the algorithm

//----------------------

std::string longestPalindromeTABULATION(std::string s) {

	if (s.length() <= 1) {
		return s;
	}

	int max_len = 1;
	int start = 0;
	int end = 0;

	std::vector<std::vector<bool>> dp(s.length(), std::vector<bool>(s.length(), false));

	for (int i = 0; i < s.length(); ++i) {

		dp[i][i] = true;

		for (int j = 0; j < i; ++j) {


			if (s[j] == s[i] && (i - j <= 2 || dp[j + 1][i - 1])) {

				dp[j][i] = true;


				if (i - j + 1 > max_len) {

					max_len = i - j + 1;

					start = j;

					end = i;
				}
			}
		}
	}

	return s.substr(start, end - start + 1);
}


int main()
{
	cout << longestPalindromeROUNDED("axhbabdfu");
}

//for (int i = 0, int j = 0; j > i; i++, j--)
//{
//
//}