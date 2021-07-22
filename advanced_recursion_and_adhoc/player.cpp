#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int max1=0;
	int max2=0;
	
	int c1=0;
	int c2 =0;
	while(n--)
	{
		int s1;
		int s2;	
		cin >> s1 >> s2;
		c1+=s1;
		c2+=s2;
		if(c1 >= c2)
		{
			if(c1-c2 > max1)
			{
				max1 = c1-c2;
			}
		}
		else
		{
			if(c2-c1 > max2)
			{
				max2 = c2-c1;
			}
		}
	}
	(max1 > max2)?(cout << 1 << " " << max1):(cout << 2 << " " << max2);

}