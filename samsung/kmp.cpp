#include<bits/stdc++.h>
using namespace std;


int* getlps(string pattern)
{
	int len = pattern.length();
	int* output = new int[len];
	// intialization
	output[0]=0;
	int j=0;
	int i=1;
	while(i<len)
	{
		if(pattern[i]==pattern[j])
		{
			// if they are equal
			output[i]=j+1;
			i++;
			j++;
		}
		else
		{
			if(j!=0)
			{
				j = output[j-1];
			}
			else
			{
				output[i]=0;
				i++;
			}
		}
	}
	for(int i=0;i<pattern.size();i++)
	{
		cout << output[i] << " ";
	}
	cout << endl;
	return output;
}
void solve(string input,string pattern)
{
	int* lps = new int[pattern.size()]();
	lps = getlps(pattern);
	for(int i=0;i<pattern.size();i++)
	{
		cout << lps[i] << " ";
	}
	cout << endl;
	int m = input.size();
	int n = pattern.size();
	int i=0;
	int j=0;
	while(i<m)
	{
		if(j==n)
		{
			cout << "found " << i-j << endl; 
			j=lps[j-1];
		}
		if(input[i]==pattern[j])
		{
			i++;
			j++;
		}
		else
		{
			if(j!=0)
			{
				j=lps[j-1];
			}
			else
			{
				i++;
			}
		}
	}
	if(j==n)
	{
		cout << "found " << i-j << endl; 
	}
	return;
}

int main()
{
	string input,pattern;
	cin >> input >> pattern;
	solve(input,pattern);
	return 0;
}