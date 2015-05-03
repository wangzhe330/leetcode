/*

Unique Paths II

Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,

There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
[0,0,0],
[0,1,0],
[0,0,0]
]

The total number of unique paths is 2.

Note: m and n will be at most 100.

*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
		int dp[100][100];
		memset(dp, 0, 10000 * sizeof(int));
		dp[0][0] = 1&(1-obstacleGrid[0][0]);
		int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();
		for (int i = 0; i < m; i++){
			for (int j = 0; j < n; j++){
				if (i == 0 && j>0)
					dp[i][j] = dp[i][j - 1]&(1-obstacleGrid[i][j]);
				else if (j == 0 && i>0)
					dp[i][j] = dp[i - 1][j] & (1 - obstacleGrid[i][j]);
				else if (i != 0 && j != 0)
				{
					if (obstacleGrid[i][j] == 1)
						dp[i][j] = 0;
					else
						dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
				}
			}
		}
		return dp[m - 1][n - 1];
	}
};
void main()
{
	Solution mySolu;
	vector<vector<int> >Grid = {
		{ 0, 0, 0 },
		{ 0, 1, 0 },
		{ 0, 0, 0 }
	};

	cout << "result is : " << mySolu.uniquePathsWithObstacles(Grid) << endl;
}