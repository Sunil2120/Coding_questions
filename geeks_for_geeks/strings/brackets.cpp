#include<bits/stdc++.h>
using namespace std;

bool solve(string input)
{
	int n = input.size();
	vector<char> stack;
	for(int i=0;i<n;i++)
	{
		if(input[i]=='(' || input[i]=='[' || input[i]=='{')
		{
			stack.push_back(input[i]);
		}
		else
		{
			if(stack.size()==0)
			{
				return false;
			}
			char cur = stack.back();
			if(input[i]==')'&& cur!='(')
			{
				return false;
			}
			if(input[i]==']' && cur!='[')
			{
				return false;
			}
			if(input[i]=='}' && cur!='{')
			{
				return false;
			}
			stack.pop_back();
		}
	}
	if(stack.size()>0)
	{
		return false;
	}
	return true;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		string input;
		cin >> input;
		cout << solve(input) << endl;
	}
}