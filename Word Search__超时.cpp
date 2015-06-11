/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
["ABCE"],
["SFCS"],
["ADEE"]
]

word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

char dp[1000][1000];

bool dfs(char** board, int boardRowSize, int boardColSize, char* word, int x, int y, int index)
{
	if (index == strlen(word)){
		return true;
	}
	if (index < strlen(word) && board[x][y] == word[index])
	{
		//dp[x][y] = 1;
		if (((x - 1 >= 0) && (dp[x - 1][y] == 0) && dfs(board, boardRowSize, boardColSize, word, x - 1, y, index + 1)) ||
			((x + 1 < boardRowSize) && (dp[x + 1][y] == 0) && dfs(board, boardRowSize, boardColSize, word, x + 1, y, index + 1)) ||
			((y - 1 >= 0) && (dp[x][y - 1] == 0) && dfs(board, boardRowSize, boardColSize, word, x, y - 1, index + 1)) ||
			((y + 1 < boardColSize) && (dp[x][y + 1] == 0) && dfs(board, boardRowSize, boardColSize, word, x, y + 1, index + 1)))
			return true;
		else
		{
			//dp[x][y] = 0;
			return false;
		}
	}
	return false;
}


bool exist(char** board, int boardRowSize, int boardColSize, char* word) {
	int index = 0;
	for (int i = 0; i < boardRowSize; i++){
		for (int j = 0; j < boardColSize; j++){
			if (dfs(board, boardRowSize, boardColSize, word, i, j, index))
				return true;
		}
	}
	return false;
}


/*
char para_board[][4] = {
	{ 'A', 'B', 'C', 'E' },
	{ 'S', 'F', 'S', 'S' },
	{ 'A', 'D', 'E', 'E' },
};*/


void main()
{
	char** para_board = (char**)malloc(100 * 100);
	//para_board[0] = "ABCE";
	//para_board[1] = "SFCS";
	//para_board[2] = "ADEF";
	//char *target = "ABCCED";

	para_board[0] = "a";
	char* target = "a";

	if (exist( (char **)para_board , 3, 4, target))
		cout << "exist" << endl;
	else
		cout << "nop" << endl;


	while (1);
}