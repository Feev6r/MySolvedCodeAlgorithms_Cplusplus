#include <iostream>
#include <vector>

using namespace std;

int dfs(vector<vector<int>>& grid, int i, int j) {
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != 1) {
        return -1;
    }

    grid[i][j] = 0; // mark as visited
    
    return 
        (dfs(grid, i + 1, j) + 1) + 
        (dfs(grid, i - 1, j) + 1) + 
        (dfs(grid, i, j + 1) + 1) + 
        (dfs(grid, i, j - 1) + 1);
}


int maxAreaOfIsland(vector<vector<int>>& grid) {

    if (grid.empty() || grid[0].empty()) {
        return 0;
    }

    int maxArea = 0;

    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] == 1) {
                maxArea = max((dfs(grid, i, j) + 1), maxArea);
            }
        }

    }

    return maxArea;
}

int main()
{
    std::cout << "Hello World!\n";
}

