#include <iostream>
#include <vector>

using namespace std;

class Solution {
    vector<int> original;
    int n;

public:
    Solution(vector<int>& nums) {
        original = nums;
        n = original.size();
    }

    vector<int> reset() {
        return original;
    }

    vector<int> shuffle() {

        vector<int> arr = original;

        // Sembrar el generador de números aleatorios
        std::srand(std::time(0));

        // Recorrer el array de atrás hacia adelante
        for (int i = n - 1; i > 0; --i) {
            // Obtener un índice aleatorio entre 0 y i (inclusive)
            int j = std::rand() % (i + 1);

            // Intercambiar array[i] con array[j]
            std::swap(arr[i], arr[j]);
        }

        return arr;
    }
};

int main()
{
    vector<int> arr = { 1,2,3,4 };


    for (int n : arr) {
        std::cout << n << " ";
    }


}
