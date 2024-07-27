#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

//hash table approach
int majorityElement(vector<int>& nums) {
    unordered_map<int, int> hash;

	int n = nums.size();

	for (int i = 0; i < n; i++)
	{
		if (++hash[nums[i]] > n / 2) {
			return nums[i];
		}
	}

	return 0;
}


//Moore voting algorithm
int majorityElement(vector<int>& nums) {
    int counter = 0, majority;
    
    for (int num : nums) {
        if (!counter) {
            majority = num;
        }
        counter += num == majority ? 1 : -1;
    }
    return majority;
}

//Bit manipulation approach (need to check out again the bitwise operators)
int majorityElement(vector<int>& nums) {
    int majority = 0;

    for (unsigned int i = 0, mask = 1; i < 32; i++, mask <<= 1) {

        int bits = 0;

        for (int num : nums) {
            if (num & mask) {
                bits++;
            }
        }

        if (bits > nums.size() / 2) {
            majority |= mask;
        }
    }

    return majority;
}


//mask mueve los bits a la izquierda en cada iteracion

//verificamo si hay un bit del numero actual en el de la mask

//por cada vez que terminemos de iterar vemos si los bits sson mayores al array divido entre 2

//los bits actuales se pasan al majority con OR


//0001
//0011

//0011

//0010
//0011

//0011

//NO
//0100
//0011

//NO
//1000
//0011


int main()
{
    std::cout << "Hello World!\n";
}

