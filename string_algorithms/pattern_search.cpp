//brute force takes O(length of pattern * length of string)
#include<bits/stdc++.h>
using namespace std;

// time complexity is o(n*m)
bool check(string input,string pattern)
{
	int n = input.length();
	int m = pattern.length();
	bool result;
	for(int i=0;i<=n-m;i++)
	{
		result = true;
		for(int j=0;j<m;j++)
		{
			if(input[i+j]!=pattern[j])
			{
				result = false;
				break;
			}
		}
		if(result==true)
		{
			return true;
		}
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