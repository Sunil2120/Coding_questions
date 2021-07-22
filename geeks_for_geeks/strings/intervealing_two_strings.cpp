// Interleaving of two given strings with no common characters
// 10-02-2012
// Given three strings A, B and C. Write a function that checks whether C is an interleaving of A and B. 
// It may be assumed that there is no common character between A and B (Please see this for an extended solution that handles common characters also), 
// C is said to be interleaving A and B, 
// if it contains all characters of A and B and order of all characters in individual strings is preserved.
#include<bits/stdc++.h>
using namespace std;


bool solve(string a,string b,string c)
{
	int k = c.size();
	while(k!=0)
	{
		if(a[0]==c[0])
		{
			a=a.substr(1);
		}
		else if(b[0]==c[0])
		{
			b=b.substr(1);
		}
		else if(a[0]!=c[0] && b[0]!=c[0])
		{
			return false;
		}
		k--;
		c=c.substr(1);
	}
	// if c is less than a and b means c is not shuffle of a and b
	if(a.size()!=0 || b.size()!=0)
	{
		return false;
	}
	return true;


}
int main()
{
	string a,b,c;
	cin >> a >> b >> c;
	cout << solve(a,b,c) << endl;
	return 0;
}


Pick each character of C one by one and match it with the first character in A.
 If it doesn’t match then match it with first character of B. 
 If it doesn’t even match first character of B, then return false. 
 If the character matches with first character of A, 
 then repeat the above process from second character of C, 
 second character of A and first character of B. 
 If first character of C matches with the first character of B (and doesn’t match the first character of A), 
 then repeat the above process from the second character of C, first character of A and second character of B. 
 If all characters of C match either with a character of A or a character of B and length of C is sum of lengths of A and B, 
 then C is an interleaving A and B.