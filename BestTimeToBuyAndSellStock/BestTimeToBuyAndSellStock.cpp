#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices) {
    int lsf = INT_MAX;
    int op = 0;
    int pist = 0;

    for (int i = 0; i < prices.size(); i++) {
        if (prices[i] < lsf) {
            lsf = prices[i];
        }
        pist = prices[i] - lsf;
        if (op < pist) {
            op = pist;
        }
    }
    return op;
}

int maxProfit(vector<int>& prices) {

    int buy = INT_MAX, sell = 0;

    for (int i = 0; i < prices.size(); i++) {

        buy = min(buy, prices[i]);
        sell = max(sell, prices[i] - buy);
    
    }
    
    return sell;
}


//[7,1,5,3,6,4]
//p = 7
//lfs = 7

//p = 1
//lsf = 1

//p =5
//pist = 5 - 1 =4
//op = 4

//p = 3
//pist = 3 - 1 = 2

//p = 8
//pist = 8 - 1 = 7
//op = 7

//p = 4
//pist = 4 - 1 = 3

//ANSWER: op = 7


int main()
{
    std::cout << "Hello World!\n";
}

