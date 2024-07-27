#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

vector<string> fizzBuzz(int n) {

	vector<string> ans(n);

	for (int i = 1; i <= n; i++)
	{
		if (i % 3 == 0 && i % 5 == 0) ans[i - 1] = "FizzBuzz";
		else if (i % 3 == 0) ans[i - 1] = "Fizz";
		else if (i % 5 == 0) ans[i - 1] = "Buzz";
		else ans[i - 1] = to_string(i);
	}

	return ans;

}

vector<string> fizzBuzz(int n) {
    vector<string> res(n);
    for (int i = 1; i <= n; i++) {
        res[i - 1] = to_string(i);
    }
    for (int i = 2; i < n; i += 3) {
        res[i] = "Fizz";
    }
    for (int i = 4; i < n; i += 5) {
        res[i] = "Buzz";
    }
    for (int i = 14; i < n; i += 15) {
        res[i] = "FizzBuzz";
    }
    return res;
}

int main()
{
	fizzBuzz(3);
}
