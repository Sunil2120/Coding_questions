#include<bits/stdc++.h>
using namespace std;

string solve(string input)
{
	int* c = new int[26]();
	int distinct=0;
	for(int i=0;i<input.size();i++)
	{
		c[input[i]-'a']+=1;
		if(c[input[i]-'a']==1)
		{
			distinct+=1;
		}
	}
	for(int i=0;i<26;i++)
	{
		c[i]=0;
	}
	//cout << distinct << endl;
	int start = 0;
	int min_len = INT_MAX;
	int start_index = -1;

	int count = 0;
	for(int i=0;i<input.size();i++)
	{
		c[input[i]-'a']+=1;
		if(c[input[i]-'a']==1)// distinct
		{
			count+=1;
		}
		if(count==distinct)
		{
			// decrement the window
			while(c[input[start]-'a'] > 1)
			{
				if(c[input[start]-'a']>1)
				{
					c[input[start]-'a']--;
				}
				start++;
			}
			// we will now increment the window
			//cout << start << endl;
			int distance = i-start+1;
			if(min_len > distance)
			{
				min_len = distance;
				start_index = start;
			}
			c[input[start]-'a']--;
			start++;
			count--;
		}
	}
	delete[] c;
	return input.substr(start_index,min_len);

}

int main()
{
	string input;
	cin >> input;
	cout << solve(input) << endl;
	return 0;
}