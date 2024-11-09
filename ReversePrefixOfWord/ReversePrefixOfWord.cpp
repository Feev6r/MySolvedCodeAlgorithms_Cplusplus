#include <iostream>
#include <vector>

using namespace std;

string reversePrefix(string word, char ch) {


	for (int i = 0; i < word.size(); i++)
	{
		if (word[i] == ch) {

			int j = 0;
			while (j < i)
			{
				swap(word[j], word[i]);
				j++;
				i--;
			}
			return word;

		}
	}

	return word;
}

int main()
{
    std::cout << "Hello World!\n";
}
