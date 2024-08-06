#include <iostream>
#include <vector>

using namespace std;


int dfs(vector<vector<int>>& B, vector<vector<int>>& A, int i, int j) {
    
    int m = A.size(), n = A[0].size(), res = 1;
    
    if (i < 0 || i == m || j < 0 || j == n || A[i][j] == 0) return 1;

    A[i][j] = 0;

    res &= dfs(B, A, i - 1, j);
    res &= dfs(B, A, i + 1, j);
    res &= dfs(B, A, i, j - 1);
    res &= dfs(B, A, i, j + 1);

    return res & B[i][j];
}


int countSubIslands(vector<vector<int>>& B, vector<vector<int>>& A) {
    int m = A.size(), n = A[0].size(), res = 0;

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (A[i][j] == 1)
                res += dfs(B, A, i, j);
    
    return res;
}

//O(n * m); filas * columnas.
//O(n * m); profundidad de las llamadas recursivas, la maxima seria igual al numero de celdas.


int main()
{
    std::cout << "Hello World!\n";
}

