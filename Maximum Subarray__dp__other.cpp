/*

Maximum Subarray

Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [?2,1,?3,4,?1,2,1,?5,4],
the contiguous subarray [4,?1,2,1] has the largest sum = 6.

*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;



class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int sum = nums[0], max = nums[0];
		for (int i = 1; i < nums.size(); i++){
			if (sum + nums[i]> nums[i])
				sum = sum + nums[i];
			else
				sum = nums[i];
			if (sum>max)max = sum;
		}
		return max;
	}
};

void main()
{
	Solution mySolu;

	vector<int> temp1 =  { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
	cout << "result is : " << mySolu.maxSubArray(temp1) << endl;
}