#include<bits/stdc++.h>
using namespace std;
#define d 256
#define q 101
void solve(string text,string pattern)
{
	int n = text.size();
	int m = pattern.size();
	if(m > n)
	{
		return ;
	}
	//calculating  the hash value of first window
	int pattern_value = 0;
	int text_value = 0;
	int p = 1;
	for(int i=0;i<m;i++)
	{
		pattern_value = ((pattern_value)+(p*pattern[i]));
		text_value = ((text_value)+(p*text[i]));
		p=p*d;
	}
	//cout << pattern_value << " " << text_value << endl;
	if(pattern_value==text_value)
	{
		int i;
		//check string one by one
		for(i=0;i<m;i++)
		{
			if(pattern[i]!=text[i])
			{
				break;
			}
		}
		if(i==m)
		{
			cout << 0 << " ";
		}

	}
	for(int i=1;i<=n-m;i++)
	{
		text_value = text_value - text[i-1];
		text_value = text_value + text[i+m-1]*p;
		text_value = text_value/d;
		//cout << pattern_value << " " << text_value << endl;
		if(text_value==pattern_value)
		{
			int j;
			//check string one by one
			for(j=0;j<m && i+j < n;j++)
			{
				if(pattern[j]!=text[i+j])
				{
					break;
				}
			}
			if(j==m)
			{
				cout << i << " ";
			}
		}
	}
	cout << endl;
	return ;
}

int main()
{
	string text,pattern;
	cin >> text >> pattern;
	solve(text,pattern);
	return 0;
}