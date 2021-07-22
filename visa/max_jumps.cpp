#include<bits/stdc++.h>
using namespace std;


int solve(string s)
{
	// first check the last character
	// if last character is 0 start from 0 or start from 1
	int total = 0;
	int prev = 0;
	int count  = 0;
	if(s[s.size()-1]=='0')
	{

		for(int i=0;i<s.size();i++)
		{
			if(s[i]=='0')
			{
				total+=(i-prev+1);
				prev=i;
				count+=1;
			}
		}
		if(count > 1)
			return total+1;
		return total;
	}
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='1')
		{
			total+=(i-prev);
			prev=i;
			count+=1;
		}
	}
	if(count > 1)
		return total+1;
	return total;
}
int main()
{
	string s;
	cin >> s;
	cout << solve(s) << endl;
	return 0;
}