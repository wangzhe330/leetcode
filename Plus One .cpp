
/*

Plus One

Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.

*/
#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;



class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		stack<int>rec;
		stack<int>sig_res;
		vector<int>res;
		/*
		vector<int>::iterator it = digits.end();
		it--;
		for (; it >= digits.begin(); it--){
			rec.push(*it);
			
		}*/
		rec.push(0);
		for (int i = 0;  i < digits.size(); i++){
			rec.push(digits[i]);
		}
		
		int jinwei = 0;
		
		int temp = rec.top();
		sig_res.push((temp + 1) % 10);
		if ((temp + 1 ) >= 10)
			jinwei = 1;
		else
			jinwei = 0;
		rec.pop();

		while (!rec.empty()){
			int temp = rec.top();
			sig_res.push( (temp + jinwei) % 10);
			if ((temp +jinwei) >= 10)
				jinwei = 1;
			else
				jinwei = 0;
			rec.pop();
		}
		if (sig_res.top() == 0 && sig_res.size() > 1)
			sig_res.pop();
		while(!sig_res.empty()){
			res.push_back(sig_res.top());
			sig_res.pop();
		}
		return res;
	}
};

void main()
{
	Solution mySolu;

	vector<int> temp1 =  {1,2};
	vector<int>res= mySolu.plusOne(temp1) ;
	for (int i = 0; i < res.size(); i++){
		cout << res[i]<<"  "<< endl;
	}
}