#include<bits/stdc++.h>
using namespace std;

int suni(int count)
{
	if(count==1)
	{
		return 1;
	}
	double x = count/2.0;
	int y = count/2;
	//cout << x << " " << y << " " << x-y << endl;
	if((x - y) >=0.5)
	{
		return y+1;
	}
	return y;
}

int solve(string input,int n)
{
	string output;
	int open = 0;
	for(int i=0;i<n;i++)
	{
		if(input[i]=='{')
		{
			open+=1;
		}
		else
		{
			if(open==0)
			{
				//wrong
				output.push_back(input[i]);
			}
			else
			{
				open--;
			}
		}
	}
	while(open>0)
	{
		output.push_back('{');
		open--;
	}
	cout << output << endl;
	if(output.size() & 1)
	{
		return -1;
	}
	open=0;
	int close = 0;
	for(int i=0;i<output.size();i++)
	{
		if(output[i]=='{')
		{
			open+=1;
		}
		else
		{
			close+=1;
		}
	}
	int x = suni(open);
	int y = suni(close);
	return x + y;

}
int main()
{
	string input;
	cin >> input;
	cout << solve(input,input.size()) << endl;
}