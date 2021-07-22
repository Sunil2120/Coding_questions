#include<bits/stdc++.h>
using namespace std;

// used stack here not queue
//https://www.geeksforgeeks.org/next-smaller-element/

void solve(vector<int>& input,int n)
{
	if(n==0)
	{
		return ;
	}
	vector<int> output;
	stack<int> Q;
	for(int i=n-1;i>=0;i--)
	{
		while(!Q.empty() && Q.top() >= input[i])
		{
			Q.pop();
		}
		if(Q.empty())
		{
			output.push_back(-1);
		}
		else
		{
			output.push_back(Q.top());
		}
		Q.push(input[i]);
	}
	for(int i=n-1;i>=0;i--)
	{
		cout << output[i] << " ";
	}
	cout << endl;
	return ;

}
int main()
{
	int n;
	cin >> n;
	vector<int> input(n);
	for(int i=0;i<n;i++)
	{
		cin >> input[i];
	}
	solve(input,n);
	return 0;
	
}