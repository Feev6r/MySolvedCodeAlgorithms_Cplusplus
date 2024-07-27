#include <iostream>
#include <vector>

using namespace std;

void rotate(vector<vector<int>>& matrix) {

	int row = matrix.size();

	for (int i = 0; i < row; i++) {
	
		for (int j = 0; j <= i; j++) {

			swap(matrix[i][j], matrix[j][i]);
		}
	}

	for (int i = 0; i < row; i++) {
	
		reverse(matrix[i].begin(), matrix[i].end());
	}
}

//0,0 | 0,0
//1,0 | 0,1
//1,1 | 1,1
//2,0 | 0,2
//2,1 | 1,2
//2,2 | 2,2


//0,0 | 0,2
//1,0 | 1,2
//2,0 | 2,2


//solution adding a new matrix, but doing this is not allowed 
void rotate(vector<vector<int>>& matrix) {

	int n = matrix.size() -1;

	vector<vector<int>> ans(n + 1, vector<int>(n + 1));

	for (int i = n; i >= 0; i--)
	{
		for (int j = 0; j <= n; j++)
		{
			ans[j][n - i] = matrix[i][j];
		}
	}

	matrix = ans;
}


//time = o(n)
//space = o(n)


int main()
{
	vector<vector<int>> a = { {1,2,3}, {4,5,6}, {7,8,9} };
	rotate(a);
}
