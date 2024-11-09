#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool f1(char c) {

	c = tolower(c);

	switch (c)
	{
	case 'q': return true;
		break;
	case 'w': return true;
		break;
	case 'e':return true;
		break;
	case 'r':return true;
		break;
	case 't':return true;
		break;
	case 'y':return true;
		break;
	case 'u':return true;
		break;
	case 'i':return true;
		break;
	case 'o':return true;
		break;
	case 'p':return true;
		break;
	}

	return false;
}
bool f2(char c) {


	c = tolower(c);

	switch (c)
	{
	case 'a':return true;
		break;
	case 's':return true;
		break;
	case 'd':return true;
		break;
	case 'f':return true;
		break;
	case 'g':return true;
		break;
	case 'h':return true;
		break;
	case 'j':return true;
		break;
	case 'k':return true;
		break;
	case 'l':return true;
		break;
	}
	return false;
}
bool f3(char c) {

	c = tolower(c);

	switch (c)
	{
	case 'z':return true;
		break;
	case 'x':return true;
		break;
	case 'c':return true;
		break;
	case 'v':return true;
		break;
	case 'b':return true;
		break;
	case 'n':return true;
		break;
	case 'm':return true;
		break;
	}

	return false;
}

vector<string> findWords(vector<string>& words) {

	vector<string> ans;

	for (int i = 0; i < words.size(); i++)
	{
		int n = words[i].length();

		int j = 1;
		if (f1(words[i][0])) {

			while (j < n)
			{
				if (!f1(words[i][j])) break;
				j++;
			}

			if (j != n) continue;
			ans.push_back(words[i]);
			continue;
		}

		if (f2(words[i][0])) {

			while (j < n)
			{
				if (!f2(words[i][j])) break;
				j++;
			}

			if (j != n) continue;
			ans.push_back(words[i]);
			continue;
		}

		if (f3(words[i][0])) {

			while (j < n)
			{
				if (!f3(words[i][j])) break;
				j++;
			}

			if (j != n) continue;
			ans.push_back(words[i]);
			continue;

		}

	}

	return ans;

}


int main()
{
	vector<string> v = { "Hello","Alaska","Dad","Peace" };
	findWords(v);
}



//unordered_map<char, int> m1;
//m1['q'];  m1['w'];  m1['e']; m1['r']; m1['t']; m1['y']; m1['u']; m1['o']; m1['p'];
//
//unordered_map<char, int> m2;
//m2['a'];  m2['s'];  m2['d']; m2['f']; m2['g']; m2['h']; m2['j']; m2['k']; m2['l'];
//
//unordered_map<char, int> m3;
//m3['z'];  m3['x'];  m3['c']; m3['v']; m3['b']; m3['n']; m3['m'];
//
//
//vector<unordered_map<char, int>> vmp;
//vmp.push_back(m1);
//vmp.push_back(m2);
//vmp.push_back(m3);