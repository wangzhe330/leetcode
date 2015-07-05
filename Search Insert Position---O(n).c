/*
Search Insert Position 

Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 ¡ú 2
[1,3,5,6], 2 ¡ú 1
[1,3,5,6], 7 ¡ú 4
[1,3,5,6], 0 ¡ú 0

*/


int searchInsert(int* nums, int numsSize, int target) {
	int cnt = 0;
	if (numsSize == 0)
		return 0;
	if (numsSize == 1){
		if (target == nums[0])return 0;
		else if (target > nums[0])return 1;
		else return 0;
	}
	if (target < nums[0]) return 0;
	for (cnt = 0; cnt < numsSize-1; cnt++){
		if (nums[cnt] == target) return cnt;
		else if (nums[cnt]<target && nums[cnt + 1]>target) return cnt + 1;
	}
	if(target == nums[cnt]) return cnt;
	if (target>nums[cnt])return cnt + 1;
}
