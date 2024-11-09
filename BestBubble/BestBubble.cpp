#include <iostream>
#include <vector>

using namespace std;


//the exercise says that we need to return the best sort, either descending or ascending, blablabla
void bubbleSort(vector<int>& arr, int& res) {
	int n = arr.size() - 1;
	bool swapped;

	vector<int> temp = arr;

	int asc = 0;
	int dsc = 0;

	int k = 0;

	while (k <= 1)
	{
		for (int i = 0; i < n; i++)
		{
			swapped = false;

			for (int j = 0; j < n - i; j++) {

				if (arr[j] > arr[j + 1] && k == 0) {

					swap(arr[j], arr[j + 1]);
					swapped = true;
					asc++;
				}

				if (arr[j] < arr[j + 1] && k == 1) {
					swap(arr[j], arr[j + 1]);
					swapped = true;
					dsc++;

				}
			}

			if (!swapped) {
				break;
			}
			//4, 5, 3, 2, 1
		}
		arr = temp;
		k++;

	}

	res = min(asc, dsc);
}

int main()
{
    std::cout << "Hello World!\n";
}
