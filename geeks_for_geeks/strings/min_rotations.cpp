//Minimum rotations required to get the same string

//Given a string, we need to find the minimum number of rotations required to get the same string.
#include<bits/stdc++.h>
using namespace std;

void left_rotate(string& output)
{
	output.push_back(output[0]);
	output = output.substr(1);
	return ;
}

// o(n) time
int solve(string input)
{
	string output = input;
	for(int i=1;i<input.size();i++)
	{
		left_rotate(output);
		cout << output << endl;
		if(output==input)
		{
			return i;
		}
	}
	return input.size();
}

// o(n^2) time
int solve2(string input)
{
	string temp = input + input;
	for(int i=1;i<input.size();i++)
	{
		string temp2 = temp.substr(i,input.size());
		if(temp2==input)
		{
			return i;
		}
	}
	return input.size();
}

int main()
{
	string input;
	cin >> input;
	cout << solve(input) << endl;
	cout << solve2(input) << endl;
}