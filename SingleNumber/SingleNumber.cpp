#include <iostream>
#include <vector>
#include <bitset>

using namespace std;


//por cada iteracion, se obtienen 2 numeros
//esos 2 numero se le aplican el XOR
//lo que sucedo con xor esque 
//cada bit tiene que ser diferente para que de 1
//si son iguales se cancelan
//
//por ejemplo 1010
//            1010
//            0000
//otro ejemplo
//            1010
//            0101
//            1111

//entonces sabemos que con xor esque se va cancelando o sumando
//todo depende de los bits.

int singleNumber(vector<int>& nums) {

    int ans = nums[0];

    for (int i = 1; i < nums.size(); i++) {

        ans = ans ^ nums[i];
    }


    return ans;
}


int main()
{

    int a = 0b101;
    int b = 0b10110;

    b <<= 4;

    int c = a | b;


    std::cout <<  bitset<9>(c);
}
