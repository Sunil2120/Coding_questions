#include<bits/stdc++.h>
using namespace std;


int solve(string input)
{
	int n = input.size();
	int count[256];
	for(int i=0;i<256;i++)
	{
		count[i]=0;
	}
	for(int i=0;i<n;i++)
	{
		count[input[i]]+=1;
	}
	int distinct = 0;
	for(int i=0;i<256;i++)
	{
		if(count[i] > 0)
		{
			distinct+=1;
		}
	}
	for(int i=0;i<256;i++)
	{
		count[i]=0;
	}
	int left = 0;
	int right = 0;
	int d1 = 0;
	int result = INT_MAX;
	while(right < n)
	{
		if(count[input[right]]==0)
		{
			d1+=1;
		}
		count[input[right]]+=1;
		if(d1==distinct)
		{
			while(count[input[left]] > 1)
			{
				count[input[left]]-=1;
				left+=1;
			}
			result = min(result,right-left+1);
		}
		right+=1;
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