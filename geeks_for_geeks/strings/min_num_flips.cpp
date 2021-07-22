#include<bits/stdc++.h>
using namespace std;


int solve(string input)
{
	int n = input.size();
	int check;
	if(input[0]=='0')
	{
		check = 1;
	}
	else
	{
		check = 0;
	}
	int count = 0;
	for(int i=1;i<n;i++)
	{
		int val = input[i]-'0';
		if(val!=check)
		{
			count+=1;
		}
		check = check^1;
	}
	int count1=0;
	if(input[n-1]=='0')
	{
		check = 1;
	}
	else
	{
		check = 0;
	}
	for(int i=n-2;i>=0;i--)
	{
		int val = input[i]-'0';
		if(val!=check)
		{
			count1+=1;
		}
		check = check^1;
	}
	return min(count,count1);
}

int main()
{
	string input;
	cin >> input;
	cout << solve(input) << endl;
	return 0;
}