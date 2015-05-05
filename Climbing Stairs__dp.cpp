
/*

Climbing Stairs

You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/

#include <iostream>
using namespace std;

class Solution {
public:
	int climbStairs(int n) {
		int sum[3] = {1,2,0};
		if (n <= 0) return 0;
		else if (n == 1)return 1;
		else if(n == 2)return 2;
		else
			for (int i = 2; i < n; i++){
				sum[2] = sum[1] + sum[0];
				sum[0] = sum[1];
				sum[1] = sum[2];
			}
			return sum[2];
	}
};

void main()
{
	Solution mySolu;
	int num = 0;
	while(cin >> num)
		cout << mySolu.climbStairs(num) << endl; 
}
