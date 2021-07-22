#include<bits/stdc++.h>
using namespace std;



int solve(string s,string t,int m,int n)
{

	// if the first string  is empty nothing can be done
	if(m==0)
	{
		return 1000000000;
	}
	// if second string is empty then the first character in first string itself is the shortest uncommon sequence so return 1
	if(n<=0)
	{
		return 1;
	}

	int index = -1;
	// we are finding the index of first occurance of first character
	for(int k=0;k<n;k++)
	{
		if(t[k]==s[0])
		{
			index = k;// once we get the index of first occurance loop breaks otherwise it may overwrite index of next occurances
			break;
		}
	}
	if(index == -1)// if first character in first string is not found then itself is the shortest uncommon sequence so return 1
	{
		return 1;
	}

	// include
	int temp = 1 + solve(s.substr(1),t.substr(index+1),m-1,n-index-1);// if we include that character is a part of required subsequence so adding 1 and 
																		// and checking next characters in first string and the characters next to first occurance in second string 
	// not including
	int temp1 = solve(s.substr(1),t,m-1,n);// if we don't include we will proceed to next characters in first string
											// and all characters in second string
	return min(temp,temp1);// returning minimum
}

int solve2(string a,string b,int m,int n,int** output)
{
	if(m==0)
	{
		return 100000000;
	}
	if(n<=0)
	{
		return 1;
	}
	if(output[m][n] > -1)
	{
		return output[m][n];
	}
	int index = -1;
	for(int i=0;i<n;i++)
	{
		if(b[i]==a[0])
		{
			index = i;
			break;
		}
	}
	if(index == -1)
	{
		output[m][n]=1;
		return output[m][n];
	}

	// include
	int temp = 1 + solve2(a.substr(1),b.substr(index+1),m-1,n-index-1,output);
	// not including
	int temp1 = solve2(a.substr(1),b,m-1,n,output);
	output[m][n]=min(temp,temp1);
	return output[m][n];


}

int main()
{
	string s,t;
	cin >> s >> t;
	int** output = new int*[s.size() + 1];
	for(int i=0;i<=s.size();i++)
	{
		output[i]=new int[t.size() + 1];
		for(int j=0;j<=t.size();j++)
		{
			output[i][j]=-1;
		}
	}
	cout << solve2(s,t,s.size(),t.size(),output) << endl;
	for(int i=0;i<=s.size();i++)
	{
		delete[] output[i];
	}
	delete[] output;
	return 0;
}