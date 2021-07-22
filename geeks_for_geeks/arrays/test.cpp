#include<bits/stdc++.h>
using namespace std;


int solve(string input)
{
	if(input.size()==0)
	{
		return 0;
	}
	if(input.size()==1)
	{
		return 1;
	}
	int check = 0;
	int i=0;
	string temp1 = input;
	string temp2 = input;
	while(i<temp1.size())
	{
		if((temp1[i]-'0')==check)
		{
			string a = temp1.substr(0,i)+temp1.substr(i+1);
			temp1 = a;
			check = check^1;
		}
		else
		{
			i+=1;
		}
	}
	i = 0;
	check = 1;
	while(i<temp2.size())
	{
		if((temp2[i]-'0')==check)
		{
			string a = temp2.substr(0,i)+temp2.substr(i+1);
			temp2 = a;
			check = check^1;
		}
		else
		{
			i+=1;
		}
	}
	int first = 1000000;
	int second = 1000000;
	if(temp1!=input)
	{
		first = solve(temp1)+1;
	}
	if(temp2!=input)
	{
		second = solve(temp2)+1;
	}
	return min(first,second);
}
int main()
{
	string input;
	cin >> input;
	cout << solve(input) << endl;
	return 0;
}