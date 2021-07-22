// Z algorithm is used to find the given pattern in a given string
// time complexity o(n+m)
// Z function is used to get the Z array which stores the length of  longest substring starting from that index which is also the prefix of the string
#include<bits/stdc++.h>
using namespace std;

void Z_func(string str,int* z)
{
	int l=0;
	int r=0;
	int n = str.length();
	for(int i=1;i<str.length();i++)
	{
		// case 1
		if(i>r)
		{
			l=i;
			r=i;
			while(r<n && str[r-l]==str[r])
			{
				r+=1;
			}
			z[i]=r-l;
			r--;
		}
		else
		{
			int suni = i-l;
			if(z[suni]+i <= r)// case 2
			{
				z[i]=z[suni];
			}
			else
			{
				// case 3
				l=i;
				while(r<n && str[r-l]==str[r])
				{
					r+=1;
				}
				z[i]=r-l;
				r--;
			}
		}

	}
}


void check(string input,string pattern)
{
	string str = pattern + "$" + input;
	int* z = new int[str.length()]();
	Z_func(str,z);
	for(int i=0;i<str.length();i++)
	{
		if(z[i]==pattern.length())
		{
			cout << i-pattern.length()-1 << endl;
		}
	}
	return ;
}


int main()
{
	string input,pattern;
	cin >> input >> pattern;
	check(input,pattern);
	return 0;
}