#include <iostream>
#include <vector>

using namespace std;


bool searchMatrix(vector<vector<int>>& matrix, int target) {

    int curCol = matrix[0].size() - 1;
    int curRow = 0;

    while (curCol >= 0 && curRow < matrix.size())
    {
        if (target == matrix[curRow][curCol]) {
            return true;
        }
        else if (target < matrix[curRow][curCol]) {
            curCol--;
        }
        else {
            curRow++;
        }
    }

    return false;
}

int main()
{
    vector<vector<int>> v = { {-5} };
    searchMatrix(v, -5);
}
