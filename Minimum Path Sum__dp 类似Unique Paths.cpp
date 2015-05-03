/*

Minimum Path Sum

Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Solution {
public:
	int min(int a, int b){
		return a < b ? a : b;
	}
	int minPathSum(vector<vector<int> > &grid) {
		//int dp[100][100];
		vector<vector<int>> dp(grid);
		//memset(dp, 0, 10000 * sizeof(int));
		if (grid.empty())return 0;
		dp[0][0] = grid[0][0];
		int m = grid.size();
		int n = grid[0].size();
		for (int i = 0; i < m; i++){
			for (int j = 0; j < n; j++){
				if (i == 0 && j>0)
					dp[i][j] = dp[i][j - 1]+grid[i][j];
				else if (j == 0 && i>0)
					dp[i][j] = dp[i - 1][j]+grid[i][j];
				else if (i != 0 && j != 0)
				{
					dp[i][j] =min( dp[i - 1][j] , dp[i][j - 1])+grid[i][j];
				}
			}
		}
		return dp[m - 1][n - 1];
	}
};

void main()
{
	Solution mySolu;
	vector<vector<int>> Grid;
	vector<int> temp1 = { 1, 2 ,9,10 };
	vector<int>temp2 = { 3, 4 ,5,1};
	Grid.push_back(temp1);
	Grid.push_back(temp2);
	cout << "result is : " << mySolu.minPathSum(Grid) << endl;
}