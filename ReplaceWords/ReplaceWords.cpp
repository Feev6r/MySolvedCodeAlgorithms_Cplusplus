#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

string replaceWords(vector<string>& dictionary, string sentence) {

	string ans = "";
	unordered_map<char, int> mp;
	int m = sentence.length();

	for (int i = 0; i < dictionary.size(); i++) {
		
		if (!mp.count(dictionary[i][0]) || dictionary[i].length() < dictionary[mp[dictionary[i][0]]].length()) {
			mp[dictionary[i][0]] = i;
		}
	} 

	for (int i = 0; i < m; i++)
	{
		if (mp.count(sentence[i]) && (i == 0 || (i > 0 && sentence[i -1] == ' '))) {

			int wordSize = dictionary[mp[sentence[i]]].length();
			string sub = sentence.substr(i, wordSize);

			if (dictionary[mp[sentence[i]]] == sub) {

				ans += sub;
				i += wordSize;

				while (sentence[i] != ' ' && i < m) {
					i++;
				}
			}

		}

		if(i + 1 < m) ans += sentence[i];
	}

	return ans;

} //no sirve

int main()
{

	//vector<string> dictionary = { "cat","bat","rat" };
	//string s = "the cattle was rattled by the battery";


	vector<string> dictionary = { "a", "aa", "aaa", "aaaa" };
	string s = "a aa a aaaa aaa aaa aaa aabbb bbb baba ababa";


	cout << replaceWords(dictionary, s);
}
