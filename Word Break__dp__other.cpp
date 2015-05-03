/*

Word Break

Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".

*/

#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	bool wordBreak(string s, unordered_set<string>& wordDict) {
		vector<bool> dp(s.size() + 1, false);
		dp[0] = true;
		for (int i = 1; i < s.size()+1; i++){
			for (int j = i - 1; j >=0; j--){
				if (dp[j] == true){
					string word = s.substr(j, i - j);
					if (wordDict.find(word) != wordDict.end()){
						dp[i] = true;						
					}
					break;
				}
			}
		}
		return dp[s.size()];
	}
};


void main()
{
	string str="aaaaaa";
	unordered_set<string> wd;
	wd.insert("aaaa");
	wd.insert("aa");
	Solution mySolu;
	if (mySolu.wordBreak(str, wd))
		cout << "yess" << endl;
	else
		cout << "no" << endl;
}