#include<bits/stdc++.h>
using namespace std;

int solve(string input)
{
	stack<int> s;// stores the indices of the opening bracket
	s.push(-1);
	int result = INT_MIN;
	for(int i=0;i<input.size();i++)
	{
		if(input[i]=='(')
		{
			s.push(i);
		}
		else
		{
			if(s.size() > 0)
			{
				s.pop();
			}
			if(s.size()>0)
			{
				result = max(result,i-s.top());
			}
			else
			{
				s.push(i);
			}
		}
	}
	return result;
}

int main()
{
	string input;
	cin >> input;
	cout << solve(input) << endl;
	return 0;
}