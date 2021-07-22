#include<bits/stdc++.h>
using namespace std;


// longest prefix which is also a suffix algo o(m)(m->length of string)
int* lps(string pattern)
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
	return output;
}

// time complexity o(n) + o(m)
bool check(string input,string pattern)
{
	int n = input.length();
	int m = pattern.length();
	int* lp = lps(pattern);
	for(int i=0;i<m;i++)
	{
		cout <<lp[i] << " ";
	}
	cout << endl;
	int i=0;
	int j=0;
	while(i<n && j<m)
	{
		if(input[i]==pattern[j])
		{
			// if characters  are equal continue
			i++;
			j++;
		}
		else
		{
			// if characters are not equal
			if(j!=0)
			{
				j=lp[j-1];
			}
			else
			{
				i++;
			}
		}
	}
	if(j==m)
	{
		return true;
	}
	return false;
}

int main()
{
	string input,pattern;
	cin >> input >> pattern;
	cout << check(input,pattern) << endl;
	return 0;
}