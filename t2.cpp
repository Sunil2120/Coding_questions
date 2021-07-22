#include<bits/stdc++.h>
using namespace std;


int solve(int u,int l)
{
	if(u==0 || l==0)
	{
		return 0;
	}
	if(u >= l)
	{
		// form a square
		return 1 + solve(u-l,l);
	}
	
	return 1 + solve(l-u,u);
}

int main()
{
	int l1,l2,b1,b2;
	cin >> l1 >> l2 >> b1 >> b2;
	int total = 0;
	for(int i=l1;i<=l2;i++)
	{
		for(int j=b1;j<=b2;j++)
		{
			total+=solve(i,j);
		}
	}
	cout << total << endl;
	return 0;

}