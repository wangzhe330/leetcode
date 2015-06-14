/*

Reverse Integer

Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321

click to show spoilers.
Have you thought about this?

Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!

If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.

Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?

For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

Update (2014-11-10):
Test cases had been added to test the overflow behavior.


*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void my_itoa(int x, char* dst){
	int len = 1;
	int temp = x;
	while (temp / 10){
		len++;
		temp /= 10;
	}
	dst[len] = 0;
	temp = x;
	for (; len > 0; len--){
		dst[len-1] = temp%10 + '0';
		temp /= 10;
	}
}

int reverse(int x) {
	int res = 0;
	int temp = x;
	char src[20];
	char dst[20];
	int len = 0;
	int count = 0;
	if (x < 0)
		temp = 0 - x;
	//_itoa_s(temp, src, 10);
	//puts(src);
	my_itoa(temp, src);

	len = strlen(src);
	for (count = len; count > 0; count--){
		dst[len-count] = src[count-1];
	}
	dst[len ] = 0;
	if (x > 0 && strlen(dst) >= strlen("2147483647") && strcmp(dst, "2147483647") > 0) return 0;
	if (x<0 && strlen(dst) >= strlen("2147483647")&& strcmp(dst, "2147483648")>0) return 0;
	res = atoi(dst);
	if (x < 0)
		res = 0 - res;
	return res;
}

void main()
{
	int para = 0;
	while(scanf_s("%d", &para))
		printf("result = %d\n", reverse(para));
}