// Number of substrings with count of each character as k
// Last Updated: 24-04-2019
// Given a string and an integer k, 
// find number of substrings in which all the different characters occurs exactly k times.
#include<bits/stdc++.h>
using namespace std;

// check other characters count
bool check(int* c,int k)
{
	for(int i=0;i<26;i++)
	{
		if(c[i]!=0 && c[i]!=k)
		{
			return false;
		}
	}
	return true;
}

int solve(string input,int k)
{
	int n = input.size();
	int count = 0;
	for(int i=0;i<n;i++)
	{
		int* c = new int[26]();
		for(int j=i;j<n;j++)
		{
			c[input[j]-'a']+=1;
			if(c[input[j]-'a']>k)
			{
				break;
			}
			else if(c[input[j]-'a']==k && check(c,k)==true)
			{
				cout << input.substr(i,j-i+1) << endl;
				count+=1;
			}
		}
		delete[] c;
	}
	return count;
}

int main()
{
	string input;
	cin >> input;
	int k;
	cin >> k;
	cout << solve(input,k) << endl;
	return 0;
}