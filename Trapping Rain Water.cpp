

/*

Trapping Rain Water

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example,
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.


*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

#include <stdio.h>
#include <stdlib.h>

using namespace std;

class Solution {
public:
	int trap(vector<int>& height) {
		int sum = 0;
		int front = 0, back;
		if (height.size() == 0)return 0;
		back = height.size() - 1;
		while (height[front] == 0) front++;
		while (height[back] == 0)back--;
		while (front < back){
			if (height[front] < height[back]){
				int tmp = front;
				front++;
				while (front < back && height[front] < height[tmp]){
					sum += height[tmp] - height[front];
					front++;
				}
			}
			else{
				int tmp = back;
				back--;
				while (front < back && height[back] < height[tmp]){
					sum += height[tmp] - height[back];
					back--;
				}
			}
		}
		return sum;

	}
};

int main()
{
	Solution mySolu;
	vector<int>para ;
	cout << "result is : " << mySolu.trap(para) <<endl;
}