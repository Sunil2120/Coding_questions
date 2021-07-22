#include<bits/stdc++.h>
using namespace std;


int main()
{
	string input;
	cin >> input;
	int n = input.size();
	//upper case 65
	// lower case 97;
	char first = input[0];
	int capital = 0;
	if(first <  97)// capital
	{
		capital = 1;
	}
	char second = input[1];
	int capital1 = 0;
	if(second < 97)
	{
		capital1 = 1;
	}
	cout << capital << " " << capital1 << endl;
	if(capital1 == capital)
	{
		for(int i=2;i<n;i++)
		{
			int temp = 0;
			if(input[i] < 97)
			{
				temp = 1;
			}
			
			if(temp!=capital)
			{
				cout << "False" << endl;
				return 0;
			}
		}
		
	}
	else
	{
		for(int i=2;i<n;i++)
		{
			int temp = 0;
			if(input[i] < 97)
			{
				temp = 1;
			}
			
			if(temp!=capital1)
			{
				cout << "False" << endl;
				return 0;
			}
		}
	}
	cout << "True" << endl;
	return 0;
}