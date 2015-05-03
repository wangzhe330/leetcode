class Solution {
public:
	void reverseWords(string &s) {
		string::iterator s_it;
		string::iterator s_end = s.end();
		int i = 0, j = 0;
		stack<string> s_stack;
		string sub;
		for (s_it = s.begin(); s_it != s_end; s_it++, i++)
		{
			if (*s_it == ' ')
			{
				sub = s.substr(j, i - j);
				if (sub.size() != 0)
					s_stack.push(s.substr(j, i - j));
				j = i + 1;
			}
			//cout << *s_it << endl;
		}
		sub = s.substr(j, i - j);
		if ( sub.size() != 0 )
			s_stack.push( sub );
		//cout << s_stack.size() << endl;
		int stack_size = s_stack.size();
		for (int cnt = 0; cnt<stack_size; cnt++)
		{
			if (cnt == stack_size - 1) cout << s_stack.top();
			else cout << s_stack.top() << ' ';
			s_stack.pop();
		}
	}
};