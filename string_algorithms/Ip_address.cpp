#include<iostream>
#include<string>
using namespace std;

int getval(string input)
{
	int n = input.size();
	int total = 0;
	int suni = 1;
	for(int i=n-1;i>=0;i--)
	{
		int val = (input[i] - '0')*suni;
		total+=val;
		suni = suni*10;
	}
	return total;
}

bool isvalid(string input)
{
	if(input.size() > 3)
	{
		return false;
	}
	if(input[0]=='0' && input.size() > 1)
	{
		return false;
	}
	if(getval(input) < 0 || getval(input) > 255)
	{
		return false;
	}
	return true;
}


void solve(string input)
{
	int n = input.size();
	for(int i=1;i<n && i<4;i++)
	{
		string first = input.substr(0,i);
		if(isvalid(first)==false)
		{
			continue;
		}
		for(int j=1;i+j<n && j<4;j++)
		{
			string second = input.substr(i,j);
			if(isvalid(second)==false)
			{
				continue;
			}
			for(int k=1;i+j+k<n && k<4;k++)
			{
				string third = input.substr(i+j,k);
				string fourth = input.substr(i+j+k);
				if(isvalid(third)==false || isvalid(fourth)==false)
				{
					continue;
				}
				cout << first << "." << second << "." << third << "." << fourth << endl;
			}
		}
	}
	return ;
}

int main()
{
	string input;
	cin >> input;
	solve(input);
	return 0;
}