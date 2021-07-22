#include<bits/stdc++.h>
#define M 1000000007
using namespace std;


int solve(string input,int n)
{
	if(n==0)
	{
		return 0;
	}
	
	long long total = input[0] -'0';
	long long last = input[0] - '0';
	for(int i=1;i<n;i++)
	{
		last = ((last*10) + (input[i]-'0')*(i+1));
		last = last%M;
		total = (last + total)%M;
	}

	return total;
}


int main()
{
	string input;
	cin >> input;
	cout << solve(input,input.size()) << endl;
	return 0;
}