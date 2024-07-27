#include <iostream>
#include <vector>

double findMedianSortedArrays2(std::vector<int>& nums1, std::vector<int>& nums2) {

	double sum = 0;

	for (int n : nums1)
	{
		sum += n;
	}
	for (int n : nums2)
	{
		sum += n;
	}

	return sum / (nums1.size() + nums2.size());

}

double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {

	int num1Index = 0;
	int num2Index = 0;
	int resultIndex = 0;
	int num1Size = nums1.size();
	int num2Size = nums2.size();

	std::vector<int> SortedArr(num1Size + num2Size);

	while (num1Index < num1Size && num2Index < num2Size)
	{
		if (nums1[num1Index] <= nums2[num2Index]) {

			SortedArr[resultIndex] = nums1[num1Index];
			num1Index++;
		}
		else {

			SortedArr[resultIndex] = nums2[num2Index];
			num2Index++;
		}

		resultIndex++;
	}

	while (num1Index < num1Size) {

		SortedArr[resultIndex] = nums1[num1Index];
		num1Index++;
		resultIndex++;
	}

	while (num2Index < num2Size) {
		SortedArr[resultIndex] = nums2[num2Index];
		num2Index++;
		resultIndex++;

	}

	int midIndex = 0;
	double Result = 0;


	if (SortedArr.size() % 2 == 0) {
		midIndex = SortedArr.size() / 2;
		Result = static_cast<double>(SortedArr[midIndex] + SortedArr[midIndex - 1]) / 2;
	}
	else {
		midIndex = SortedArr.size() / 2 + 1;
		Result = SortedArr[midIndex - 1];
	}

	return Result;

}

int main()
{
	std::vector<int> a;
	std::vector<int> b;

	a.push_back(1);
	a.push_back(2);
	b.push_back(3);
	b.push_back(4);


	double d = findMedianSortedArrays(a, b);
	//double d = findMedianSortedArrays2(a,b);

	std::cout << d;

	//std::cout << 3 / 2

	//for (int num : d)
	//{
	//	std::cout << num << " ";
	//}
}
