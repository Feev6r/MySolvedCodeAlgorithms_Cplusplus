#include <iostream>

using namespace std;

int ZeroCount(int L, int K) {

	if (K == 0) return 0;
	else if (K == L) return K;
	else {
		int zeros = L - K;
		int gaps = K + 1;
		int q = zeros / gaps;
		int remainder = zeros % gaps;

		if (remainder > 0) {
			return q + 1;
		}
		else {
			return q;
		}
	}
}

int main()
{
	int L;
	int K;
	cin >> L >> K;
	ZeroCount(L, K);
}

