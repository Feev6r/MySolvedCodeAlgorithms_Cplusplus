#include <iostream>
#include <vector>

using namespace std;

int hammingWeight(int n) {

	int bits = 0;

	for (unsigned int i = 0, mask = 1; i < 32; i++, mask <<= 1) 
	{
		if (n & mask) bits++;
	}

	return bits;

}

int hammingWeight(uint32_t n) {
    int count = 0;

    while (n) {
        n &= (n - 1);
        count++;
    }

    return count;
}



int main()
{
    std::cout << "Hello World!\n";
}