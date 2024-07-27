#include <iostream>
#include <unordered_map>
#include <cctype>

using namespace std;

void questionsMarks(string str) {

	int size = str.length();
	unordered_map<int, int> nums;

	for (int i = 0; i < size; i++) {

		if (isdigit(str[i])) {
			nums[str[i] - '0'] = i;
		}
	}


}


int main()
{
	
	questionsMarks("acc?7??sss?3rr1??????5");


	
}

//string str = "aa6?9";
//
//string cleanStr;
//unordered_map<int, int> map;
//int size = str.length();
//
//bool result = false;
//
//for (int i = 0; i < size; i++)
//{
//	char cur = str[i];
//
//	if (!std::isalpha(static_cast<unsigned char>(cur))) { //no es una palabra
//		cleanStr += cur;
//	}
//}
//
//for (int i = 0; i < cleanStr.length(); i++)
//{
//
//	if (cleanStr[i] != '?') {
//
//		int a = cleanStr[i] - 48;
//		map[a] = i;
//	}
//}
//
//
//int rSize = cleanStr.length();
//
//for (auto& a : map) {
//
//	if ((a.second + 4) <= rSize) {
//
//
//		if (cleanStr[a.second] != '?' && cleanStr[a.second + 4] != '?') {
//
//
//			if (static_cast<int>(cleanStr[a.second]) + static_cast<int>(cleanStr[a.second + 4]) >= 10) {
//				result = true;
//			}
//		}
//	}
//
//}