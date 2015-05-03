class Solution {
public:
	void rotate(int nums[], int n, int k) {
		reverse(nums, nums + n);			//整体反转过来
		reverse(nums, nums + k%n);			//对前k%n反转
		reverse(nums + k%n, nums + n);		//对后k%n~n进行反转
	}
};
