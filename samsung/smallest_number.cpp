#include<bits/stdc++.h>
using namespace std;

string solve(string input,int n)
{
	if(n==0)
	{
		return input;
	}
	string res = "";
	if(input.size() <= n)
	{
		return res;
	}
	// we should find the smallest digit in first n+1 character
	int min_index = 0;
	for(int i=1;i<=n;i++)
	{
		if(input[i] < input[min_index])
		{
			min_index = i;
		}
	}
	res.push_back(input[min_index]);
	res+=solve(input.substr(min_index+1),n-min_index);
	return res;
}

int main()
{

	string input;
	cin >> input;
	int n;
	cin >> n;
	cout << solve(input,n) << endl;
	return 0;
}