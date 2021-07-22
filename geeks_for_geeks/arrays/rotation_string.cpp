
// A Program to check if strings are rotations of each other or not
// 26-05-2009
// Given a string s1 and a string s2, write a snippet to say whether s2 is a rotation of s1?
// (eg given s1 = ABCD and s2 = CDAB, return true, given s1 = ABCD, and s2 = ACBD , return false)
#include<bits/stdc++.h>
using namespace std;


int* lps(string pattern)
{
	int* arr = new int[pattern.size()];
	arr[0]=0;
	int j=0;
	int i=1;
	while(i<pattern.size())
	{
		if(pattern[j]==pattern[i])
		{
			// if they are equal
			arr[i]=j+1;
			j+=1;
			i+=1;
		}
		else
		{
			if(j!=0)
			{
				j=arr[j-1];
			}
			else
			{
				arr[i]=0;
				i+=1;
			}
		}
	}
	return arr;
}

bool check(string input,string pattern)
{
	int n = input.length();
	int m = pattern.length();
	int* l = lps(pattern);
	int i=0;
	int j=0;
	while(i<n && j<m)
	{
		if(input[i]==pattern[j])
		{
			i+=1;
			j+=1;
		}
		else
		{
			if(j!=0)
			{
				j=l[j-1];
			}
			else
			{
				i+=1;
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
	string input;
	cin >> input;
	string input1;
	cin >> input1;
	string temp = input.append(input);
	cout << check(temp,input1) << endl;
}