/*

House Robber

You are a professional robber planning to rob houses along a street. 
Each house has a certain amount of money stashed, 
the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police 
if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, 
determine the maximum amount of money you can rob tonight without alerting the police.

*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:

	int fun(vector<int>& nums , int n)
	{
		
		n--;
		if (n == 0)
			return nums[0];
		if (n == 1){
			return max(nums[0], nums[1]);
		}
		if (n > 1)
			return max( fun(nums,n-2) + nums[n], fun(nums,n-1));
	}
	int max(int a, int b){
		return a > b ? a : b;
	}
	int rob(vector<int>& nums) {
		if (nums.empty())
			return 0;
		//return fun(nums,nums.size());
		vector<int>dp(nums.size(),-1);
		dp[0] = nums[0];
		dp[1] = max(nums[0], nums[1]);
		for (int i = 2; i < nums.size(); i++)
		{
			dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
		}
		return dp[nums.size() - 1];
	}
};
void main()
{
	Solution mySolu;
	vector<int> money = { 10, 20, 30 , 10  ,100 , 900 ,10};
	cout << "max is : " << mySolu.rob(money);
}