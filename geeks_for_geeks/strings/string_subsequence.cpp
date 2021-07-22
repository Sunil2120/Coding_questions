#include<bits/stdc++.h>
using namespace std;


int solve(string input,string* output)
{
	if(input.size()==0)
	{
		output[0]=" ";
		return 1;
	}
	int sm = solve(input.substr(1),output);
	for(int i=0;i<sm;i++)
	{
		output[i+sm]=input[0] + output[i];
	}
	return 2*sm;
}

// recursion
void solve1(string input,string output)
{
	if(input.size()==0)
	{
		cout << output << endl;
		return ;
	}
	// ignore
	solve1(input.substr(1),output);
	// include
	solve1(input.substr(1),output+input[0]);
}

int main()
{
	string input;
	cin >> input;
	int n = pow(2,input.length());
	string* output = new string[n];
	int size = solve(input,output);
	for(int i=0;i<size;i++)
	{
		cout << output[i] << endl;
	}
	solve1(input,"");
	return 0;
}