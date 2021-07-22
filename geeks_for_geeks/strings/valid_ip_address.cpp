// refer amell perlta youtube channel

#include<bits/stdc++.h>
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
	// max length  of the segment should be 3
	if(input.length() > 3)
	{
		return false;
	}
	// segment should not have 0 leading 
	// 0 is valid but 00 01 02 are not valid
	if(input[0]=='0' && input.length() > 1)
	{
		return false;
	}
	int val = getval(input);
	if(val < 0 || val > 255)
	{
		return false;
	}
	return true;
}

// o(n^3) time and o(1) auxillary space
void solve(string input)
{
	// we will place . after 1 character
	int n = input.length();
	for(int i=1;i<n && i<4;i++)
	{
		string first = input.substr(0,i);
		if(isvalid(first)==false)
		{
			// this string is not valid we should try next
			continue;
		}
		// if it is valid
		for(int j=1;i+j<n && j<4;j++)
		{
			string second = input.substr(i,j);
			if(isvalid(second)==false)
			{
				continue;// not valid try next iteration
			}

			for(int k=1;i+j+k < n && k<4 ;k++)
			{
				string third = input.substr(i+j,k);
				string fourth = input.substr(i+j+k);
				if(isvalid(third)==false || isvalid(fourth)==false)
				{
					continue;// not valid try next
				}
				cout << first + "." + second + "." + third + "."+fourth << endl;
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