#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    bool flag1 = false, flag2 = false;

    for (int i = 0; i < n; i++) {
        if (matrix[i][0] == 0) {
            flag1 = true;
        }
    }
    for (int j = 0; j < m; j++) {
        if (matrix[0][j] == 0) {
            flag2 = true;
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = matrix[0][j] = 0;
            }
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }
    if (flag1 == true) {
        for (int i = 0; i < n; i++) {
            matrix[i][0] = 0;
        }
    }
    if (flag2 == true) {
        for (int j = 0; j < m; j++) {
            matrix[0][j] = 0;
        }
    }
}


void setZeroes2(vector<vector<int>>& matrix) {

	unordered_map<int, int> row;
	unordered_map<int, int> column;
	int n = matrix.size();
	int m = matrix[0].size();

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (matrix[i][j] == 0) {
				row[i];
				column[j];
			}
		}
	}
	
	for (auto& r : row) {
		int t = 0;

		while (t < m) {
			matrix[r.first][t] = 0;
			t++;
		}
	}

	for (auto& c : column) {
		int t = 0;

		while (t < n) {
			matrix[t][c.first] = 0;
			t++;
		}
	}

}


int main()
{

	vector<vector<int>> v = { {0,1,2,0} ,{3,4,5,2},{1,3,1,5} };
    vector<vector<int>> v2 = { {1,1,1} ,{1,0,1},{1,1,1} };
	setZeroes(v2);
}

