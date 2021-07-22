#include<bits/stdc++.h>
using namespace std;


int solve(string input)
{
	unordered_map<char,int> hash;
	int count = 0;
	for(int i=0;i<input.size();i++)
	{
		if(input[i] >=97 && input[i] <= 122 )
		{
			if(hash[input[i]]==0)
			{
				count+=1;	
			}
			hash[input[i]]+=1;
		}
	}
	return count;
}


int main()
{
	string input;
	getline(cin,input);
	cout << solve(input) << endl;
}