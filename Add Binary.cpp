/*
Add Binary 

Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".

*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	string addBinary(string a, string b) {
		
		int len_a = a.length();
		int len_b = b.length();
		int index =( len_a > len_b ? len_a : len_b )+ 1;
		string result(index,'c');
		index--;
		len_a--;
		len_b--;
		int mid = 0;
		int tmp = 0;
		int cnt = 0;

		while (len_a >= 0 && len_b >= 0){
			tmp = a[len_a--] - '0' + b[len_b--] - '0' + mid;
			if (tmp > 1){
				mid = 1;
				result[index--] = tmp % 2 + '0';
			}
			else{
				mid = 0;
				result[index--] = tmp + '0';
			}
		}
		while (len_a >= 0){
			tmp = a[len_a--] - '0' + mid;
			if (tmp > 1){
				mid = 1;
				result[index--] = tmp % 2 + '0';
			}
			else{
				mid = 0;
				result[index--] = tmp + '0';
			}
		}
		while (len_b >= 0){
			tmp = b[len_b--] - '0' + mid;
			if (tmp > 1){
				mid = 1;
				result[index--] = tmp % 2 + '0';
			}
			else{
				mid = 0;
				result[index--] = tmp + '0';
			}
		}
		if (mid > 0){
			result[index--] = mid + '0';
		}
		
		if (index >= 0){
			result = result.substr(1, result.length() - 1);
		}
		

		return result;

	}
};

int main(){
	Solution mySolu;
	string s1, s2;
	cin >> s1 >> s2;
	cout << mySolu.addBinary(s1, s2) << endl;
}