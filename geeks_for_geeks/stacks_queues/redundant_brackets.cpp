#include<bits/stdc++.h>
using namespace std;

void solve(string input)
{
	stack<char> s;
	for(int i=0;i<input.size();i++)
	{
		if(input[i]==')')
		{
			// we will pop until ')'
			int check = 0;
			while(s.size() > 0 && s.top()!='(')
			{
				check=1;
				s.pop();
			}
			if(check==0)//there is nothing inside ()
			{
				cout << "Yes" << endl;
				return;
			}
			if(s.size() > 0)
			{
				s.pop();
			}
			
		}
		else
		{
			s.push(input[i]);
		}
	}
	cout << "false" << endl;
	return ;
}

int main()
{
	string input;
	cin >> input;
	solve(input);
	return 0;
}