class Solution {
public:
	void rotate(int nums[], int n, int k) {
		reverse(nums, nums + n);			//���巴ת����
		reverse(nums, nums + k%n);			//��ǰk%n��ת
		reverse(nums + k%n, nums + n);		//�Ժ�k%n~n���з�ת
	}
};
