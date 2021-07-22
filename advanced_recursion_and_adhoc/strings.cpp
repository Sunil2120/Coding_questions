#include<bits/stdc++.h>
using namespace std;


char solve_(string input)
{
	map<char,int> freq;
	for(int i=0;i<input.length();i++)
	{
		freq[input[i]]++;//initially it will be 0
	}
	for(int i=0;i<input.length();i++)
	{
		if(freq[input[i]]==1)
		{
			return input[i];
		}
	}
	return input[0];

}

int main()
{
	string suni="aabbccd";
	cout << solve_(suni) << endl;
	return 0;
}