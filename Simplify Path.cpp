/*

Simplify Path

Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"

click to show corner cases.
Corner Cases:

Did you consider the case where path = "/../"?
In this case, you should return "/".
Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
In this case, you should ignore redundant slashes and return "/home/foo".


*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <string>
#include <stack>
#include <iostream>

using namespace std;

class Solution {
public:
	string simplifyPath(string path) {
		stack<string> temp;
		string result;
		string top;
		int begin = 1;
		string dir;
		size_t i = 1;

		if (path == "")
			return "";
		for (; i < path.length(); i++)
		{
			if (path[i] == '/')
			{
				dir = path.substr(begin, i - begin);
				if (dir != ""){
					if (dir == ".."){
						if (!temp.empty())
							temp.pop();
					}
					else if (dir == ".");
					else temp.push(dir);
				}

				begin = i+1;
			}
		}
		if (path[i - 1] != '/'){
			dir = path.substr(begin, i - begin);
			if (dir != ""){
				if (dir != ""){
					cout << dir << endl;
					if (dir == ".."){
						if (!temp.empty())
							temp.pop();
					}
					else if (dir == ".");
					else temp.push(dir);
				}
			}
			begin = i + 1;
		}
		if (temp.empty()) return "/";
		while (!temp.empty()){
			top = temp.top();
			top = top +  result;
			top = "/" + top;
			result = top;
			temp.pop();
		}
		return result;
	}
	
};

void main()
{
	Solution mySolu;
	string para;
	while(getline(cin, para))
		cout << "the result is : " << mySolu.simplifyPath(para) << endl;
}