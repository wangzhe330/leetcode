
/*

Pascal's Triangle

Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
	[1],
	[1, 1],
	[1, 2, 1],
	[1, 3, 3, 1],
	[1, 4, 6, 4, 1]
]
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> result;
		if (numRows == 0) return result;
		vector<int> RowTemp;
		RowTemp.push_back(1);
		result.push_back(RowTemp);
		RowTemp.clear();
		for (int i = 1; i < numRows; i++)
		{
			RowTemp.push_back(1);
			if (result[i - 1].size() > 1){
				for (size_t j = 0; j < result[i - 1].size()-1; j++){
					RowTemp.push_back(result[i - 1][j] + result[i - 1][j + 1]);
				}
			}
			RowTemp.push_back(1);
			result.push_back(RowTemp);
			RowTemp.clear();
		}
		return result;
	}
};

void printVV(vector<vector<int> >para){
	for (int i = 0; i < para.size(); i++){
		for (int j = 0; j < para[i].size(); j++){
			cout << " " << para[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	Solution mySolu;
	printVV(mySolu.generate(5));
}