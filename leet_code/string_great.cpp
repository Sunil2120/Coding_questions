#include<bits/stdc++.h>
using namespace std;

void solve(string input,string& output)
{
	if(input.size()==0)
	{
		output = "";
		return;
	}
	int check = 0;
	for(int i=0;i<input.size()-1;i++)
	{
		if(abs(input[i]-input[i+1])==32)
		{
			input = input.substr(0,i)+input.substr(i+2);
			check = 1;
			break;
		}
	}
	if(check == 1)
	{
		solve(input,output);
	}
	else
	{
		output = input;
	}
	return ;
	
}


int main()
{
	string input;
	cin >> input;
	string output;
	solve(input,output);
	cout << output << endl;
}