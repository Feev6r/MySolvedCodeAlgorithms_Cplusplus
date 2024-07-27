#include <iostream>


void f(int n) {

	if (n == 0) {
		std::cout << "*" << std::endl;
		return;
	}

	for (int i = 0; i < n; i++)
	{
		f(n - 1);
	}
}

int main()
{
	f(3);
}
