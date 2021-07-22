#include<bits/stdc++.h>
using namespace std;


int main()
{
	string input;
	cin >> input;
	int zero_count =0;
	int one_count = 0;
	int count =0;
	for(int i=0;i<input.size();i++)
	{
		if(input[i]=='0')
		{
			zero_count+=1;
		}
		else
		{
			one_count+=1;
		}
		if(zero_count==one_count)
		{
			count+=1;
		
		}
	}
	if(zero_count!=one_count)
	{
		cout << -1 << endl;
	}
	else
	{
		cout << count << endl;
	}
	return 0;
}