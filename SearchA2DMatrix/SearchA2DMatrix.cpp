#include <iostream>
#include <vector>

using namespace std;


bool search(vector<vector<int>>& matrix, int start, int end, int target) {

    if (start >= end) return false;

    int mid = (end - start) / 2 + start;

    if (matrix[mid / matrix[0].size()][mid % matrix[0].size()] == target) return true;


    if (target < matrix[mid / end][mid % end]) return search(matrix, start, mid - 1, target);
    else return search(matrix, mid + 1, end, target);

}

bool searchMatrix(vector<vector<int>>& matrix, int target) {

   return search(matrix, 0, (matrix.size() * matrix[0].size()) -1, target);
}

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int left = 0;
    int right = matrix.size() * matrix[0].size() - 1;

    while (left <= right) {

        int mid = left + (right - left) / 2;

        if (matrix[mid / matrix[0].size()][mid % matrix[0].size()] == target) {
            return true;
        }
        else if (matrix[mid / matrix[0].size()][mid % matrix[0].size()] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return false;
}

int main()
{
    std::cout << "Hello World!\n";
}
