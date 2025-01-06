#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	bool solve(vector<vector<char>>& board, vector<vector<bool>>& row, vector<vector<bool>>& col, vector<vector<bool>>& subGrid,
		int r, int c) {

		if (r > 8 || c > 8) {
			return true;
		}

		for (int i = 0; i < 9; i++)
		{
			if (board[r][c] == '.') { //skip numbers

				if (row[r][i] || col[c][i] || subGrid[(r / 3) * 3 + (c / 3)][i]) continue;
				board[r][c] = (i + '0') + 1; //add number

				row[r][i] = true;
				col[c][i] = true;
				subGrid[(r / 3) * 3 + (c / 3)][i] = true;
			}
			else {
				i = -1;
			}

			if (solve(board, row, col, subGrid, r, c + 1)) { //iterate through the columns first

				if (c < 8) return true; //end all

				if (solve(board, row, col, subGrid, r + 1, 0)) { //after the columns are finished, lets go down		
					return true;
				}
			}

			//backtrack 
			if (i != -1) {

				board[r][c] = '.';
				row[r][i] = false;
				col[c][i] = false;
				subGrid[(r / 3) * 3 + (c / 3)][i] = false;
			}
		}

		return false;
	}


	void solveSudoku(vector<vector<char>>& board) {

		int num = 9;

		//hash table
		vector<vector<bool>> row(num, vector<bool>(num, false));
		vector<vector<bool>> col(num, vector<bool>(num, false));
		vector<vector<bool>> subGrid(num, vector<bool>(num, false));

		for (int r = 0; r < num; ++r)
		{
			for (int c = 0; c < num; ++c)
			{
				if (board[r][c] == '.') continue;

				int idx = board[r][c] - '0' - 1;
				int gridNum = (r / 3) * 3 + (c / 3); //this way we get the grid number

				row[r][idx] = true;
				col[c][idx] = true;
				subGrid[gridNum][idx] = true;
			}
		}

		solve(board, row, col, subGrid, 0, 0);
	}
};


class Solution2 {
public:
	void solveSudoku(vector<vector<char>>& board) {
		doSolve(board, 0, 0);
	}

private:
	bool doSolve(vector<vector<char>>& board, int row, int col) {
		for (int i = row; i < 9; i++, col = 0) { // Reiniciar col en cada nueva fila
			for (int j = col; j < 9; j++) {

				if (board[i][j] != '.') continue;

				for (char num = '1'; num <= '9'; num++) {

					if (isValid(board, i, j, num)) {

						board[i][j] = num;

						if (doSolve(board, i, j + 1))
							return true;

						board[i][j] = '.';
					}
				}
				return false;
			}
		}
		return true;
	}

	bool isValid(vector<vector<char>>& board, int row, int col, char num) {

		int blkrow = (row / 3) * 3;
		int blkcol = (col / 3) * 3;

		for (int i = 0; i < 9; i++) {

			if (board[i][col] == num ||
				board[row][i] == num ||
				board[blkrow + i / 3][blkcol + i % 3] == num)
				return false;
		}
		return true;
	}
};


int main()
{
	Solution2 s;
	vector<vector<char>> sudoku = {
		{'5','3','.','.','7','.','.','.','.'},
		{'6','.','.','1','9','5','.','.','.'},
		{'.','9','8','.','.','.','.','6','.'},
		{'8','.','.','.','.','.','.','3','.'},
		{'4','.','.','8','.','3','.','.','1'},
		{'7','.','.','.','2','.','.','.','6'},
		{'.','6','.','.','.','.','2','8','.'},
		{'.','.','.','4','1','9','.','.','5'},
		{'.','.','.','.','8','.','.','7','9'}
	};
	s.solveSudoku(sudoku);
}
