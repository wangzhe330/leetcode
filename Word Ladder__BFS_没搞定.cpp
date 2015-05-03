/*

Word Ladder

 Given two words (beginWord and endWord), and a dictionary, find the length of shortest transformation sequence from beginWord to endWord, such that:

    Only one letter can be changed at a time
    Each intermediate word must exist in the dictionary

For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]

As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:

    Return 0 if there is no such transformation sequence.
    All words have the same length.
    All words contain only lowercase alphabetic characters.



Given two words (beginWord and endWord), and a dictionary, find the length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary

For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]

As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:

Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.



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



class Solution {
public:
	//unordered_map<pair<string, string>, int> rec;
	bool IsOneCharDiff(string a, string b){
		int sum = 0;
		size_t length = a.length();
		for (size_t i = 0; i < length; i++)
		{
			if (a[i] != b[i])
				sum++;
		}
		if (sum == 1)return true;
		else 
			return false;
	}
	int path(string beginw, string endw, unordered_set<string>& wordDict, int level){
		vector<int>rec;
		if (IsOneCharDiff(beginw, endw))
			return level + 1;
		else
		{
			unordered_set<string>::iterator it = wordDict.begin();
			for (; it != wordDict.end(); it++){
				if (IsOneCharDiff(beginw, *it)){
					rec.push_back ( path(*it, endw, wordDict, level + 1));
				}
			}
		}
		int min = 999999;
		for (int i = 0; i < rec.size(); i++){
			if (rec[i] < min) min = rec[i];
		}
		return min;
	}
	int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
		queue<pair<string,int>> unvisited;
		unordered_set<string> visited;
		unvisited.push(make_pair(beginWord,1));
		vector<int>rec;

		while (!unvisited.empty()){
			pair<string,int> Pair = unvisited.front();
			string s = Pair.first;

			if (IsOneCharDiff(s, endWord))
			{
				rec.push_back(Pair.second+1);
			}

			unordered_set<string>::iterator it = wordDict.begin();
			for (; it != wordDict.end() ; it++){
				if (visited.find(*it) == visited.end())
					if (IsOneCharDiff(s, *it)){
						unvisited.push(make_pair(*it,Pair.second+1));
					}
			}
		
			visited.insert(s);
			unvisited.pop();
		}
		if (rec.size() == 0)return 0;
		int min = 9999;
		for (int i = 0; i < rec.size(); i++)
		{
			if (min>rec[i])
				min = rec[i];
		}
		return min;
		/*
		unordered_set<string> visited;
		unordered_set<string> unvisited(wordDict);
		vector<int> rec;
		unordered_set<string>::iterator it = wordDict.begin();
		for (; it != wordDict.end(); it++){
			if (IsOneCharDiff(beginWord, *it)){
				rec.push_back(path(*it, endWord, wordDict, 2));
			}
		}
		int min = 99999;
		for (int i = 0; i < rec.size(); i++){
			if (min>rec[i])
				min = rec[i];
		}
		return min;
		
		*/
		//while ()

		/*int result = 999999;
		pair<string, string> Pair = make_pair(beginWord, endWord);
		if (rec.find(Pair) != rec.end())
		{
			return rec[Pair];
		}
		pair<string, string> Pair_rec;
		unordered_set<string>::iterator it = wordDict.begin();
		for (; it != wordDict.end(); it++){
			if (*it != beginWord){
				int temp = ladderLength(beginWord, *it, wordDict)+ladderLength(*it,endWord,wordDict);
				if (temp < result){
					result = temp;
					Pair_rec = make_pair(beginWord, *it);
				}
			}
		}
		if (rec.find(Pair_rec) == rec.end())
			rec.insert(make_pair(Pair_rec, result));
		else
			rec[Pair_rec] = result;
		return result;*/
	}
};


void main()
{
	Solution mySolu;
	string start, end;
	cout << "dog" - "dcg" << endl;
	while (cin >> start >> end){
		unordered_set < string >dict = { "hot", "dot", "dog", "lot", "log" };
		cout << "result = " << mySolu.ladderLength(start, end, dict);
	}
}