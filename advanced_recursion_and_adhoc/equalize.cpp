#include<bits/stdc++.h>
using namespace std;



int main()
{
	string a;
	string b;
	cin >> a >> b;
	int cost = 0;
	for(int i=0;i<a.size();)
	{
		if(a[i]!=b[i])
		{
			if( i < a.size() && a[i]!= a[i+1] && a[i+1]!=b[i+1])
			{
				char temp = a[i];
				a[i]=a[i+1];
				a[i+1]=temp;
				i+=2;
			}
			else
			{
				if(a[i]=='0')
				{
					a[i]='1';
				}
				else
				{
					a[i]='0';
				}
				i++;
			}
			cost++;

		}
		else
		{
			i++;
		}
	}
	cout << cost << endl;
	cout << a << endl;
	cout << b << endl;
}