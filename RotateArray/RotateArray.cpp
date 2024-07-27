#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//temp[(i + k) % n]
//
//2 + 3 = 5
//
//5 % 8 = 5
//
//temp[5] = temp[2]
//
//
//
//5 + k % 3
//
//8 % 3 = 2
//
//temp[2] = temp[5]
//
//
//
//Empieza en el indice k y va aumentando
//finaliza en cuando i + k sea igual a n
//si 8 % 8 = 0
//quedan k numeros restantes
//empiezan ingresando desde 0 hasta que el for finalice

//best solution:
void rotate2(vector<int>& nums, int k) {
	
	int n = nums.size();
	
	k = k % n;
	
	if (k == 0) return;

	vector<int> temp(n);
	for (int i = 0; i < n; ++i) {

		temp[(i + k) % n] = nums[i];
	}

	nums = temp;
}

void rotate(vector<int>& nums, int k) {

	int size = nums.size();

	k = k % size; //asegurarse que esta dentro del rango

	reverse(nums.begin() + (size - k), nums.end());

	reverse(nums.begin(), nums.end() - k);

	reverse(nums.begin(), nums.end());

}

int main()
{
	vector<int> v = { 1,2,3,4,5,6,7 };
	rotate2(v, 3);

	//cout << 5 % 8;

	for (int i : v) {
		cout << i << " ";
	}

}
