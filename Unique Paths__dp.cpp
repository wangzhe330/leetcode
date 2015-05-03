/*

Unique Paths

A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

Note: m and n will be at most 100.

*/
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	int uniquePaths(int m, int n) {
		int dp[100][100];
		memset(dp, 0, 10000*sizeof(int));
		dp[0][0] = 1;
		for (int i = 0; i < m; i++){
			for (int j = 0; j < n; j++){
				if (i == 0 && j>0)
					dp[i][j] = dp[i][j - 1];
				else if (j == 0 && i>0)
					dp[i][j] = dp[i - 1][j];
				else if (i!=0&&j!=0)
				{
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
	int m = 0, n = 0;
	cin >> m >> n;
	cout <<"result is : " << mySolu.uniquePaths(m,n)<< endl;
}