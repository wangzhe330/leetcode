/*
Interleaving String

Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

For example,
Given:
s1 = "aabcc",
s2 = "dbbca",

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

//#define INT_MAX 2147483647 
//#define INT_MIN -2147483648


bool dp[200][200];

bool isInterleave(char* s1, char* s2, char* s3) {
	
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	int len3 = strlen(s3);

	if (len3>len1 + len2)
		return false;

	if (len1==0 && len2 ==0 && len3==0)
		dp[0][0] = true;
	if (len1 == 0 && len2 == 0 && len3 != 0)
		dp[0][0] = false;

	for (int i = 1; i < len1 + 1; i++){
		dp[0][i] = !(strncmp(s1, s3, i));
	}
	for (int i = 1; i < len2 + 1; i++){
		dp[i][0] = !(strncmp(s2, s3, i));
	}
	for (int i = 1; i < len2+1; i++){
		for (int j = 1; j < len1+1; j++){
			dp[i][j] = (dp[i][j - 1] && (s1[j - 1] == s3[i+j-1])) || (dp[i - 1][j] && (s2[i - 1] == s3[i+j-1]));
		}
	}

	return dp[len2][len1];
}


void main()
{
	char buf1[4096];
	char buf2[4096];
	char buf3[4096];

	int i = strncmp("abc", "afbfc", 1);

	while (gets_s(buf1)){
		gets_s(buf2);
		gets_s(buf3);
		cout << (isInterleave(buf1,buf2,buf3)?"yes":"no")<< endl;
		memset(buf1, 0, 4096);
		memset(buf2, 0, 4096);
		memset(buf3, 0, 4096);
	}
	while (1);
}