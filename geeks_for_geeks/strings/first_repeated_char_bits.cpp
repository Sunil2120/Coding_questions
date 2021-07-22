// Efficiently find first repeated character in a string without using any additional data structure in one traversal
// Last Updated: 09-01-2019
// Implement a space efficient algorithm to check First repeated character in a string without using any additional data structure in one traversal. Use additional data structures like count array, hash, etc is not allowed.

// Examples :

// Input :  abcfdeacf
// Output : char = a, index= 6
#include<bits/stdc++.h>
using namespace std;


// instead of keeping a  count array we can use bits
// integer has 32 bits, we have 26 characters, if a char occurs we will set the bit

int solve(string input)
{
	int n = input.size();
	if(n==0)
	{
		return -1;
	}
	int bit = 0;
	for(int i=0;i<n;i++)
	{
		int index = input[i]-'a';
		// we will check index bit is set or not.
		if((bit & (1 << index))==0)// bit is not set
		{
			bit = bit | (1 << index);
		}
		else
		{
			// bit is set
			// repeated
			return i;
		}
	}
	return -1;
}
int main()
{
	string input;
	cin >> input;
	int ans = solve(input);
	if(ans!=-1)
	{
		cout << input[ans] << endl;
	}
	else
	{
		cout << -1 << endl;	
	}
	return 0;

}