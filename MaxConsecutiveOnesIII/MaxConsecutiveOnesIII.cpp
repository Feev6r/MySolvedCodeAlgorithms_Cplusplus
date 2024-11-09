#include <iostream>
#include <vector>

using namespace std;

int longestOnes(vector<int>& nums, int k) {
	int zeros = 0;
	int currOnesSum = 0;
	int maxOneSum = 0;
	int windowStart = 0;

	for (size_t i = 0; i < nums.size(); i++)
	{
		zeros += nums[i] == 0 ? 1 : 0;
		currOnesSum += nums[i] == 1 ? 1 : 0;

		while (zeros > k) {
			//currOnesSum += zeros;
			maxOneSum = max(maxOneSum, currOnesSum + min(k, zeros));

			if (nums[windowStart] == 0) {
				windowStart++;
				zeros--;
			}
			else {
				windowStart++;
				currOnesSum--;
			}
		}
	}

	maxOneSum = max(maxOneSum, currOnesSum + min(k, zeros));
	return maxOneSum;
}


int longestOnes2(vector<int>& nums, int k) {
	int i = 0, j = 0;

	while (j < nums.size()) {
		if (nums[j] == 0) {
			k--;
		}
		if (k < 0) {
			if (nums[i] == 0) {
				k++;
			}
			i++;
		}
		j++;
	}
	return j - i;
}

int longestOnes3(vector<int>& nums, int k) {
	int maxlen = 0, L = 0;

	for (int R = 0; R < nums.size(); R++) {

		if (nums[R] == 0) k--;

		while (k < 0) {

			if (nums[L] == 0) k++;
			L++;
		}

		maxlen = max(maxlen, R - L + 1);
	}

	return maxlen;
}

int longestOnes4(vector<int>& A, int K) {
	int i = 0, j;

	for (j = 0; j < A.size(); ++j) {

		if (A[j] == 0) K--;

		if (K < 0 && A[i++] == 0) K++;
	}

	return j - i;
}

int main()
{
	vector<int> v = { 1,1,1,0,0,0,1,1,1,1,0 };
	longestOnes4(v, 2);
}

