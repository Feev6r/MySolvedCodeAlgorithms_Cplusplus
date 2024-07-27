#include <iostream>
#include <unordered_map>

int main()
{
	std::string s = "abcabcbb";
	std::unordered_map<char, int> map;

	int max = 0;
	int count = 0;
	for (int i = 0; i < s.length(); i++)
	{

		if (map.find(s[i]) == map.end()) {
			map[s[i]] = i;
			count++;

			if (max < count) {
				max = count;
			}
		}
		else {
			
			i = map[s[i]];
			count = 0;
			map.clear();
		}
	}

	std::cout << max;
}
