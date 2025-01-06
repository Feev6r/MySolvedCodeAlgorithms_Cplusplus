#include <iostream>
#include <vector>

using namespace std;

//MY MISERABLE SOLUTION HAHA
bool solve(vector<vector<char>>& board, int row, int col, string word, vector<vector<bool>> &flag) {

	if (row >= board.size() || col >= board[0].size()) {
		return false;
	}

	if (flag[row][col]) {
		return false;
	}
	flag[row][col] = true;


	if (word.empty()) {
		return true;
	}


	if (word[0] == board[row][col]) {		
		if (word.size() != 1) word = word.substr(1);
		else return true;		
	}
	else {
		return false;
	}

	bool a = 
		solve(board, row, col + 1, word, flag) ||
		   solve(board, row, col - 1, word, flag) ||
		   solve(board, row + 1, col, word, flag) ||
		   solve(board, row - 1, col, word, flag);

	flag[row][col] = false;

	return a;
}

bool exist(vector<vector<char>>& board, string word) {


	for (int r = 0; r < board.size(); r++)
	{
		for (int c = 0; c < board[0].size(); c++)
		{
			vector<vector<bool>> flags(board.size(), vector<bool>(board[0].size(), false));

			if (solve(board, r, c, word, flags)) {
				return true;
			}
		}
	}

	return false;
}



//BEST SOLUTION
class Solution {
public:
    // Main function to check if the word exists on the board
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(); // Number of rows in the board
        int m = board[0].size(); // Number of columns in the board

        vector<vector<bool>> visited(n, vector<bool>(m, false)); // Array to keep track of visited cells

        // Convert the word into a character array
        vector<char> wordChar(word.begin(), word.end());

        // Quick check: If the length of the word exceeds the total number of cells on the board, it can't exist
        if (wordChar.size() > n * m)
            return false;

        vector<int> counts(256, 0); // Array to store counts of each character

        // Count the occurrence of each character on the board
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                counts[board[i][j]]++;
            }
        }

        // Adjust the order of characters in the wordChar array based on their frequency counts to optimize search
        int len = wordChar.size();

        for (int i = 0; i < len / 2; i++) {

            if (counts[wordChar[i]] > counts[wordChar[len - 1 - i]]) {

                for (int j = 0; j < len / 2; j++) {

                    char temp = wordChar[j];
                    wordChar[j] = wordChar[len - 1 - j];
                    wordChar[len - 1 - j] = temp;
                }
                break;
            }
        }
        //DECCBA
        // Decrease counts of characters in the word from the board
        for (char c : wordChar) {
            if (--counts[c] < 0)
                return false; // If there are more occurrences of a character in the word than on the board, return false
        }

        // Iterate through each cell in the board and start searching for the word
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (visit(board, wordChar, 0, i, j, n, m, visited))
                    return true; // If the word is found starting from this cell, return true
            }
        }
        return false; // If the loop completes without finding the word, return false
    }

    // Helper function to recursively search for the word starting from a given cell
    bool visit(vector<vector<char>>& board, vector<char>& word, int start, int x, int y, int n, int m, vector<vector<bool>>& visited) {
        // Base case: If all characters in the word are found, return true
        if (start == word.size())
            return true;

        // Check for out-of-bounds, already visited cells, and character mismatch
        if (x < 0 || x >= n || y < 0 || y >= m || visited[x][y])
            return false;

        // If the current character in the word does not match the character on the board, return false
        if (word[start] != board[x][y])
            return false;

        visited[x][y] = true; // Mark the current cell as visited

        // Recursively search in all four directions from the current cell
        bool found = visit(board, word, start + 1, x + 1, y, n, m, visited)
            || visit(board, word, start + 1, x - 1, y, n, m, visited)
            || visit(board, word, start + 1, x, y + 1, n, m, visited)
            || visit(board, word, start + 1, x, y - 1, n, m, visited);

        visited[x][y] = false; // Backtrack: Unmark the current cell as visited

        return found; // Return whether the word was found starting from the current cell
    }
};


int main()
{
    Solution s;

    string w = "ABCCED";
    vector<vector<char>> v = { {'A','B','C' , 'E'}, {'S', 'F', 'C', 'S'},{'A', 'D', 'E', 'E'}};
    s.exist(v, w);
}
