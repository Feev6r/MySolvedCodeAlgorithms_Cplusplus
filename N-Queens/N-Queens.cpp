#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<string>> sols; // 2D vector of strings to store the solutions
	vector<vector<string>> solveNQueens(int n) {

		vector<string> board(n, string(n, '.'));  // creating an empty board
		solve(board, 0); // calling the recursive function
		return sols;

	}
	bool isSafe(vector<string>& board, int row, int col) {

		int n = size(board);
		for (int i = 0; i < n; i++) {
			// checking if there is a queen in the same column
			if (board[i][col] == 'Q') return false;
			// checking if there is a queen in the same diagonal (left to right)
			if (row - i >= 0 && col - i >= 0 && board[row - i][col - i] == 'Q') return false;
			if (row - i >= 0 && col + i < n && board[row - i][col + i] == 'Q') return false;
			// No need to traverse more since the lower rows below current row attribute will always be safe.
		}
		return true;
	}
	// Recursive Function (solve) - It basically tries all possible placement of queen for the current row & recurses for it's next row
	void solve(vector<string>& board, int row) {
		// Base condition. 
		// We reached the last row, so we have a solution so we add it to the solution vector
		if (row == size(board)) {
			sols.push_back(board);
			return;
		}
		// Try placing a queen on each column for a given row. 
		// Explore next row by placing Q at each valid column for the current row
		for (int col = 0; col < size(board); col++) {
			if (isSafe(board, row, col)) {
				board[row][col] = 'Q';    // Queen placed on a valid cell
				solve(board, row + 1);    // Exploring next row
				board[row][col] = '.';    // Backtracking to get all possible solutions
			}
		}
	}
};

//faster i guess, but the other one is a good solution too

class Solution {
private:
	bool isSafePlace(int n, vector<string>& nQueens, int row, int col) {
		for (int i = 0; i < n; i++) {
			if (nQueens[i][col] == 'Q') {
				return false;
			}
		}
		for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
			if (nQueens[i][j] == 'Q') {
				return false;
			}
		}
		for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
			if (nQueens[i][j] == 'Q') {
				return false;
			}
		}
		return true;
	}
	void solveNQueens(int n, vector<vector<string>>& output, vector<string>& nQueens, int row) {
		if (row == n) {
			output.push_back(nQueens);
			return;
		}
		for (int col = 0; col < n; col++) {
			if (isSafePlace(n, nQueens, row, col)) {
				nQueens[row][col] = 'Q';
				solveNQueens(n, output, nQueens, row + 1);
				nQueens[row][col] = '.';
			}
		}
	}
public:
	vector<vector<string>> solveNQueens(int n) {
		vector<vector<string>> output;
		vector<string> nQueens(n, string(n, '.'));
		solveNQueens(n, output, nQueens, 0);
		return output;
	}
};

int main()
{
	Solution s;

	int n = 4;
	s.solveNQueens(n);
}

