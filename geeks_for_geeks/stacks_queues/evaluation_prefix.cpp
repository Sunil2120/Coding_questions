#include<bits/stdc++.h>
using namespace std;

// time complexity O(n)
int solve(string exp)
{
	vector<int> s;
	for(int i=exp.size()-1;i>=0;i--)
	{
		if(exp[i]=='+' || exp[i]=='-' || exp[i]=='*' || exp[i]=='/')
		{
			int a = s.back();
			s.pop_back();
			int b = s.back();
			s.pop_back();
			switch(exp[i])
            {
                case '+': s.push_back(a+b);break;
                case '-': s.push_back(a-b);break;
                case '*': s.push_back(a*b);break;
                case '/': s.push_back(a/b);break;
            }
		}
		else
		{
			s.push_back(exp[i]-'0');
		}
	}
	int output = s.back();
	s.pop_back();
	return output;
}
int main()
{
	string exp;
	cin >> exp;
	cout << solve(exp) << endl;
	return 0;
}