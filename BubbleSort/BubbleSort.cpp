#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(vector<int>& arr) {
	int n = arr.size() -1;
	bool swapped;

	for (int i = 0; i < n; i++) {

		swapped = false;

		for (int j = 0; j < n - i; j++) {

			if (arr[j] > arr[j + 1]) {

				swap(arr[j], arr[j + 1]);
				swapped = true;
			}
		}

		if (!swapped) break;
	}
}


int main()
{
    std::cout << "Hello World!\n";
}
