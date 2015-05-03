/*

Wildcard Matching

Implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") ¡ú false
isMatch("aa","aa") ¡ú true
isMatch("aaa","aa") ¡ú false
isMatch("aa", "*") ¡ú true
isMatch("aa", "a*") ¡ú true
isMatch("ab", "?*") ¡ú true
isMatch("aab", "c*a*b") ¡ú false

*/
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include<stack>
#include<map>
#include <unordered_map>
#include <unordered_set>
using namespace std;


class Solution_old {
public:
	bool isSigMatch(char s, char p){
		return p == '*' || p == '?' || s == p;
	}
	bool isMatch(string s, string p) {
		bool result = true;
		bool flag = false;
		vector<vector<bool>> dp;
		if (s.size() == 0 && p == "*")return true;
		if (p.size() == 0 && s.size() == 0) return true;
		if (p.size() == 0) return false;
		dp.push_back(vector<bool>());
		for (int j = 0; j < s.size(); j++){
			if (p[0] == '*')
				dp[0].push_back(true);
			else
				dp[0].push_back(isSigMatch(s[j], p[0]));			
		}
		if (p[0] == '*')flag == true;
		for (int i = 1; i < p.size(); i++){
			vector<bool> temp;
			if (p[i] == '*')flag = true;
			if (flag){
				for (int j = 0; j < s.size(); j++){
					if (j<i)
						temp.push_back(true);
					else
					{
						if (p[i] == '*' || p[i] == '?'){
							if (i == j)
								temp.push_back(temp.back() && dp[i - 1][j - 1]);
							else if (j>i)
								temp.push_back(temp.back());
						}
						else
							temp.push_back(p[i] == s[j] && dp[i - 1][j - 1]);
					}
				}
			}
			else{
				for (int j = 0; j < s.size(); j++){
					if (j<i)
						temp.push_back(true);
					else
					{
						if (p[i] == '?'){
							if (i == j)
								temp.push_back(temp.back() && dp[i - 1][j - 1]);
							else if (j>i)
								temp.push_back(temp.back());
						}
						else
							temp.push_back(p[i] == s[j] && dp[i - 1][j - 1]);
					}
				}
			}
			dp.push_back(temp);
		}
		return dp[p.size()-1][s.size()-1];
	}
};

class Solution {
public:
	bool isSigMatch(char s, char p){
		return p == '*' || p == '?' || s == p;
	}
	bool isMatch(string s, string p) {
		bool result=true;
		int i= 0;
		int j = 0;
		int rec_i=0;
		int rec_j = 0;
		bool flag = false;
		while (i < s.size() || j < p.size()){
			if (p[j] == '*'){
				flag = true;
				rec_j = j;
				if (j + 1 == p.size())
					//result = result & true;
					return true;
				else
				{
					if (isSigMatch(s[i+1],p[j+1])) {
						
						i++;
						j++;
					}
					else{
						i++;
					}
				}
			}
			else if (p[j] == '?')
			{
				i++;
				j++;
				//flag = false;
			}
			else if (s[i] != p[j])
			{
				if (!flag || i <= j)
					return false;
				else
					j = rec_j;
				/*

				if (flag&&i>j)
				{
					j=rec_j;
				}
				else
					return false;
					*/
			}
			else if (s[i] == p[j]){
				i++;
				j++;
//				flag = false;
			}
			if (flag && j == p.size() && i < s.size()){
				i = s.size() - (p.size() - rec_j - 1);
				j = rec_j;
			}
		}
		return true;
		//return isSigMatch(s[i], p[j-1]);
	}
};


void main()
{
	Solution mySolu;
	string a, b;
	//while (cin >> a >> b){
		if (mySolu.isMatch("bbaaababbaaababababbb","*a*****bb"))//("abefcdgiescdfimde", "ab*cd?i*de"))
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	//}
}