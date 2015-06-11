/*
String to Integer (atoi)

Given a 2D board and a word, find if the word exists in the grid.


Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.

Update (2015-02-10):
The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button to reset your code definition.

spoilers alert... click to show requirements for atoi.
Requirements for atoi:

The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.


*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

//#define INT_MAX 2147483647 
//#define INT_MIN -2147483648


int myAtoi(char* str) {

	char* index = str;
	char* end = str;
	long long res = 0;
	long long temp = 1;
	int flag = 0;
	if (*str == 0)return 0;
	if (!(*str >= '0' && *str <= '9' || *str == '+' || *str == '-')) {
		while (!(*index >= '0' && *index <= '9' || *index == '+' || *index == '-'))
		{
			if (*index == 0) break;
			if (*index != ' ') return 0;
			index++;
		}
	}

	if (*index == '-' || *index == '+'){
		if (*index == '-') flag = 1;
		end = index + 1;
		index++;
		while (*end >= '0' && *end <= '9')
			end++;
	}
	else
	{
		end = index;
		while (*end >= '0' && *end <= '9' && *end != 0)
			end++;
	}
	end--;
	while (end >= index){
		res += (*end - '0')*temp;
		temp *= 10;
		end--;
		if (!flag && res > INT_MAX)
		{
			return INT_MAX;
		}
		if (flag && res < INT_MIN)
		{
			res = 0 - res;
			return INT_MIN;
		}
	}
	if (flag)
		res = 0 - res;
	if (res > INT_MAX)
		return INT_MAX;
	if (res < INT_MIN)
		return INT_MIN;
	return res;
}


void main()
{
	char buf[4096];
	while(gets_s(buf))
		cout << myAtoi(buf) << endl;
	while (1);
}