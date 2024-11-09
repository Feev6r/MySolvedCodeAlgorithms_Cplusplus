#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


//En esta solucion comenzamos pasandole los numeros y indices del arr para a un hash table para despues hacer la busqueda
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numMap;
        int n = nums.size();

        // Build the hash table
        for (int i = 0; i < n; i++) {
            numMap[nums[i]] = i;
        }

        // Find the complement
        for (int i = 0; i < n; i++) {
            int complement = target - nums[i];
            if (numMap.count(complement) && numMap[complement] != i) { //diferente a i, porque no pueden ser los mismo indices 
                return { i, numMap[complement] };
            }
        }

        numMap[1];

        return {}; // No solution found
    }
};

//En esta solucion, se van guardando su valor indice a medida que se va comprovando si el complement esta o no.
class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numMap;
        int n = nums.size();

        for (int i = 0; i < n; i++) {

            int complement = target - nums[i];
            
            if (numMap.count(complement)) {
                return { numMap[complement], i };
            }
            numMap[nums[i]] = i;
        }

        return {}; // No solution found
    }
};




int main()
{

}
