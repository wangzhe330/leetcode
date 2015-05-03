/*

Number of Islands

Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 
You may assume all four edges of the grid are all surrounded by water.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	void dfs(vector<vector<char>> &grid, int x, int y, int w, int h){
		if (x < 0 || x >= h || y < 0 || y >= w ) return;
		if (grid[x][y] == '0') return;
		else
		{
			grid[x][y] = '0';
			dfs(grid, x - 1, y, w, h);
			dfs(grid, x + 1, y, w, h);
			dfs(grid, x, y - 1, w, h);
			dfs(grid, x, y + 1, w, h);
		}
	}
	int numIslands(vector<vector<char>> &grid) {
		int w = 0, h = 0;
		if (grid.empty()) return 0;
		w = grid[0].size();
		h = grid.size();
		int ans = 0;
		for (int i = 0; i < h; i++){
			for (int j = 0; j < w; j++){
				if (grid[i][j] == '1'){
					ans++;
					dfs(grid,i, j, w, h);
				}
			}
		}
		return ans;
	}
};

int main()
{
	Solution mySolu;
	vector<vector<char>> Grid;//((1,1,0,0,0),(1,1,0,0,0),(0,0,1,0,0),(0,0,0,1,1));
	char init0[] = { '1', '1', '0', '0', '0' };
	size_t s_count = sizeof(init0) / sizeof(char);
	vector<char>temp0(init0, init0+s_count);

	char init1[] = { '1', '1', '0', '0', '0' };
	vector<char>temp1(init1, init1+ s_count);

	char init2[] = { '0', '0', '1', '0', '0' };
	vector<char>temp2(init2, init2 + s_count);

	char init3[] = { '0', '0', '0', '1', '1' };
	vector<char>temp3(init3, init3 + s_count);

	char init4[] = { '1', '1', '0', '0', '0' };
	vector<char>temp4(init4, init4 + s_count);
	/*
	Grid.push_back(temp0);
	Grid.push_back(temp1);
	Grid.push_back(temp2);
	Grid.push_back(temp3);*/
	//Grid.push_back(temp4);

	cout << mySolu.numIslands( Grid );
}