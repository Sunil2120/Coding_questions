#include<bits/stdc++.h>
using namespace std;


 //Fake Palindrome: Return the number of Fake Palindrome substring in a string, 
 //where Fake Palindrome is a string whose anagram is a palindrome.

//O(N2) time and O(1) auxillary space
int solve(string input)
{
	int n = input.size();
	int total = 0;
	for(int i=0;i<n;i++)
	{
		int x = 0;
		for(int j=i;j<n;j++)
		{
			x=x^(1<<(input[j]-'a'));
			if((x&(x-1))==0)//no odds or only one odd count
			{
				total+=1;
			}
		}
	}
	return total;
}

//O(26*N) time and O(N) auxillary space
int solve2(string input)
{
	int  n = input.size();
	unordered_map<int,int> hash;
	hash[0]=1;
	int x = 0;
	int ans = 0;
	for(int i=0;i<n;i++)
	{
		x = x ^ (1<<(input[i]-'a'));
		ans+=hash[x];
		for(int j=0;j<26;j++)
		{
			ans+=hash[x^(1<<j)];
		}
		hash[x]+=1;
	}
	return ans;
}

int main()
{
	string input;
	cin >> input;
	cout << solve(input) << endl;
	cout << solve2(input) << endl;
	return 0;
}