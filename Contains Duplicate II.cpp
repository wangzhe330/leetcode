/*
Contains Duplicate II

Given an array of integers and an integer k, 
find out whether there there are two distinct indices i and j in the array such that nums[i] = nums[j] and the difference between i and j is at most k. 
*/

class Solution {
public
	bool containsNearbyDuplicate(vectorint& nums, int k) {
		mapint, int existed;
		int count = 0;
		for (; count  nums.size(); count++){
			mapint, intiterator it = existed.find(nums[count]);
			if ( it != existed.end()){
				if (count - it-second = k)
					return true;
				else
				    it-second = count;
			}
			else{
				existed.insert(pairint, int( nums[count] , count));
			}
		}
		return false;
	}
};