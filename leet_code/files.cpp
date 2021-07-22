#include<bits/stdc++.h>
using namespace std;

int solve(vector<string>& input,int n)
{
	int cur = 0;
	for(int i=0;i<n;i++)
	{
		if(input[i]=="../")
		{
			cur=cur-1;
		}
		else if(input[i]=="./")
		{
			continue;
		}
		else
		{
			cur=cur+1;
		}
	}
	return cur;
}


int main()
{
	vector<string> input;
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		string temp;
		cin >> temp;
		input.push_back(temp);
	}
	cout << solve(input,n) << endl;
	return 0;
}