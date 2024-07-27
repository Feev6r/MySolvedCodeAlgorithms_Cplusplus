#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool isValidSudoku2(vector<vector<char>>& board) {
	const int num = 9;
	// Initialize boolean arrays to track digits in each row, column, and subgrid
	bool row[num][num] = { false };
	bool col[num][num] = { false };
	bool subGrid[num][num] = { false };

	// Iterate through each cell in the Sudoku board
	for (int r = 0; r < num; ++r) {
		for (int c = 0; c < num; ++c) {
			// Skip empty cells
			if (board[r][c] == '.') continue; // if not a number, proceed to the next cell

			// Convert character digit to numerical index
			int idx = board[r][c] - '0' - 1; // char to num idx
			// Determine the subgrid number based on the current cell's position
			int gridNum = (r / 3) * 3 + (c / 3);

			// Check if the number already exists in the corresponding row, column, or subgrid
			if (row[r][idx] || col[c][idx] || subGrid[gridNum][idx]) {
				return false; // if duplicate number found, the Sudoku board is invalid
			}

			// Update the boolean arrays for the current row, column, and subgrid with the current digit
			row[r][idx] = true;
			col[c][idx] = true;
			subGrid[gridNum][idx] = true;
		}
	}
	return true; // if no duplicates found, the Sudoku board is valid
}


unordered_map<int, vector<char>> isValidSudoku(vector<vector<char>>& board) {

	unordered_map<int, vector<char>> box;
	unordered_map<int, vector<char>> rows;
	unordered_map<int, vector<char>> colums;

	int a = 0;

	for (int i = 0; i < board.size(); i++)
	{
		if (i % 3 == 0) {
			a++;
		}

		for (int j = 0; j < 3; j++)
		{
			box[a].push_back(board[i][j]);
		}

	}

	return box;

}


int main()
{
	vector<vector<char>> board = {

		{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
		{'6', '.', '.', '1', '9', '5', '.', '.', '.'},
		{'.', '9', '8', '.', '.', '.', '.', '6', '.'},
		{'8', '.', '.', '.', '6', '.', '.', '.', '3'},
		{'4', '.', '.', '8', '.', '3', '.', '.', '1'},
		{'7', '.', '.', '.', '2', '.', '.', '.', '6'},
		{'.', '6', '.', '.', '.', '.', '2', '8', '.'},
		{'.', '.', '.', '4', '1', '9', '.', '.', '5'},
		{'.', '.', '.', '.', '8', '.', '.', '7', '9'}
	};

	cout << boolalpha << isValidSudoku2(board);

}
