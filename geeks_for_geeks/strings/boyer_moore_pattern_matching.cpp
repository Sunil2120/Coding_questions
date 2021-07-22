// boyer moore pattern matching algorithm using bad table approach

#include<bits/stdc++.h>
using namespace std;
#define MAX 256


void solve(string str,string pattern)
{
	int* bad_t = new int[MAX];
	for(int i=0;i<MAX;i++)
	{
		bad_t[i]=-1;
	}
	int n = str.length();
	int m = pattern.length();
	for(int i=0;i<m;i++)
	{
		int index = (int)pattern[i];
		bad_t[index]=i;
	}
	int s = 0;
	while(s <=(n-m))
	{
		int j = m-1;
		while(j>=0 && pattern[j]==str[s+j])
		{
			j--;
		}
		if(j<0)// we got a pattern
		{
			cout << s << endl;
			s+=((s+m)<n)?m-bad_t[str[s+m]]:1;
		}
		else
		{
			// j - bad_t[s+j] can be negative.
			s+=max(1,j-bad_t[str[s+j]]);
		}
	}
	return ;
}

int main()
{
	string str,pattern;
	cin >> str >> pattern;
	solve(str,pattern);
	return 0;
}