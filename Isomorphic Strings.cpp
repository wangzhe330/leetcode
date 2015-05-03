
/*

Isomorphic Strings

Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

For example,
Given "egg", "add", return true.

Given "foo", "bar", return false.

Given "paper", "title", return true.

Note:
You may assume both s and t have the same length.


*/
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <map>
#include <set>
using namespace std;


class Solution {
public:
	bool isIsomorphic(string s, string t) {
		map<string, string> table;
		set<string>rec;
		for (int i = 0; i < s.size(); i++){
			if ( table.find(s.substr(i, 1))==table.end()){				
				if (rec.find(t.substr(i, 1)) != rec.end())
					return false;
				table.insert(make_pair(s.substr(i, 1), t.substr(i, 1)));
				rec.insert(t.substr(i, 1));
			}
			else{
				if (t.substr(i, 1) != table[s.substr(i, 1)])
					return false;
			}
		}
		return true;		
	}
};

void main()
{
	Solution mySolu;
	string a;// = "egg";
	string b;
	while (cin >> a >> b){
		if (mySolu.isIsomorphic(a, b))
			cout << " yes " << endl;
		else
			cout << " no " << endl;
	}
}