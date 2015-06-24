
/*

Two Sum

Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int cmp(pair<int, int>x, pair<int, int>y){
	if (x.first >= y.first)
		return 1;
	else
		return -1;
}


class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		map<int, int>rec;
		vector<int> result;
		vector<int>tmp;
		for (size_t i = 0; i < nums.size(); i++){
			rec[nums[i]] = i;
		}

		map<int, int>::iterator it = rec.begin();
		for (; it != rec.end(); it++){
			//cout << "the value is " << it->first << "  the location is " << it->second << endl;
			tmp.push_back(it->first);
		}
		for (size_t i = 0; i < tmp.size()-1; i++)
		{
			int diff = target - tmp[i];
			int j = i + 1;
			vector<int>::iterator it_tmp = tmp.begin();
			vector<int> para_tmp(it_tmp + j, tmp.end());

			vector<int>::iterator it_res = find(para_tmp.begin(), para_tmp.end(), diff);

			if (it_res != para_tmp.end())
			{
				if (rec[*it_res] < rec[tmp[i]]){
					result.push_back(*it_res);
					result.push_back(tmp[i]);
				}
				else{
					result.push_back(tmp[i]);
					result.push_back(*it_res);

				}
			}
		}
		return 	result;
	}

};


	int dich_search(vector<int> &x, int val){
		int i = 0, j = x.size() - 1;
		if (val > x[j] || val < x[i])return -1;

		while (i < j){
			if (val == x[i])return i;
			if (val == x[j])return j;
			if (i = j - 1)return -1;
			if (val < x[(i + j) / 2]){
				j = (i + j) / 2;
			}
			else if (val > x[(i + j) / 2]){
				i = (i + j) / 2;
			}
			else
				return (i + j) / 2;
		}
		if (i == j){
			if (val == x[i])return i;
			else return -1;
		}
	}

int main()
{
	Solution mySolu;
	vector<int>para = {3,2,4};
	vector<int>res;
	int tar = 0;

	while (cin >> tar){
		
			res = mySolu.twoSum(para, tar);
			if (!res.empty()){
				cout << res[0] << " + " << res[1] << " = " << tar << endl;
			}
			else{
				cout << "no " << endl;
			}
	}
}