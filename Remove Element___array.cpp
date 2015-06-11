/*
Remove Element

Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.
*/

#include <iostream>
#include <vector>

using namespace std;




class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		vector<int>::iterator it = nums.begin();
		//vector<int>::iterator back = nums.end()-1;
		vector<int> res;
		for (; it != nums.end(); it++){
			if (*it != val){
				res.push_back(*it);
			}
		}
		nums.clear();
		it = res.begin();
		for (; it != res.end(); it++){
			nums.push_back(*it);
		}
		return res.size();
	}
};

void main()
{
	Solution mySolu;

	vector<int>para = { 1, 2, 3, 4, 5, 5, 5, 6, 7, 8, 9 };
	int target = 5;
	cout << "old length is :" << para.size() << endl;
	cout << "new length  is :" << mySolu.removeElement(para, target) << endl;
}