#include<bits/stdc++.h>
using namespace std;


int main()
{
	string input;
	cin >> input;
	int cost = 0;
	int check = 0;
	int index;
	for(index=0;index<input.size();index++)
	{
		if(input[index]=='A' || input[index]=='R')
		{
			break;
		}
	}
	char start = input[index];
	char end;
	if(start=='A')
	{
		end = 'R';
	}
	else
	{
		end = 'A';
	}
	for(int i=index;i<input.size();i++)
	{
		
		if(input[i]==start || input[i]=='G')
		{
			if(check==1)
			{
				cost+=1;
				check = 0;
			}
			continue;
		}
		if(input[i]=='B')
		{
			cost+=1;
			check = 1;
		}
		if(input[i]==end)
		{
			if(check==1)
			{
				cost+=1;
			}
			break;
		}
		
	}
	cout << cost << endl;
}