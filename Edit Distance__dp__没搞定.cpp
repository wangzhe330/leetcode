/*

Edit Distance

Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character

*/
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
	int min(int a, int b){
		return a < b ? a : b;
	}
	/*
	int minStep(string s1, string s2){
		if ()
	}*/
	int cacle(int a, int b){
		return a>b ? a : b;
	}
	int minDistance(string word1, string word2) {
		if (word1 == word2)
			return 0;
		if (word1.size()==0 &&word2.size()==0)
			return 0;
		if (word1.size() == 0)
			return word2.size();
		if (word2.size() == 0)
			return word1.size();
		map< string,pair<int, int> >rec;
		int dp[500][500];
		for (int i = 0; i < word1.size(); i++)
			dp[i][0] = 0;
		for (int i = 0; i < word2.size(); i++)
			dp[0][i] = 0;
		for (int i = 1; i <= word1.size(); i++){
			for (int j = 1; j <= word2.size(); j++){
				if (word1[i-1] == word2[j-1]){
					dp[i][j] = dp[i - 1][j - 1] + 1;
					if (rec.find(word1.substr(i - 1, 1)) == rec.end())
						rec.insert(make_pair(word1.substr(i - 1, 1), make_pair(i - 1, j - 1)));
					else
						rec[word1.substr(i - 1, 1)] = make_pair(i - 1, j - 1);
				}
				else if (dp[i - 1][j] >= dp[i][j - 1])
					dp[i][j] = dp[i - 1][j];
				else
					dp[i][j] = dp[i][j - 1];
			}
		}
		map<string,pair<int, int>>::iterator it = rec.begin();
		
		for (; it !=rec.end(); it++){
			//cout << it->first << "  " + word1.substr(it->first,1) << "  " << it->second << "  " + word2.substr(it->second,1) << endl;
			cout << it->first << " : " << (it->second).first << "  " << it->second.second << endl;
		}
		
		int sum = 0;
		if (!rec.empty())
			//sum += cacle(rec.begin()->first, rec.begin()->second);
			sum += cacle(rec.begin()->second.first, rec.begin()->second.second);
		else
			return cacle(word1.size(), word2.size());
		it = rec.begin();
		map<string,pair<int, int>>::iterator it_prev = rec.begin();
		it++;
		for (; it != rec.end(); it++){
			sum += cacle(it->second.first- it_prev->second.first-1, it->second.second - it_prev->second.second-1);
			it_prev = it;
		}
		sum += cacle(word1.size() - it_prev->second.first  - 1, word2.size() - it_prev->second.second - 1);
		return sum;
	}
};



void main()
{
	Solution mySolu;
	string s1, s2;
	cin >> s1 >> s2;
	int sum = mySolu.minDistance(s1, s2);
	cout << "steps : " << sum;
}