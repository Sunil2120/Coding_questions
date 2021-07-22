#include<bits/stdc++.h>
using namespace std;


bool solve(int m,int n,int k,int x,int y,int cur)
{
	if(x==m-1 && y==n-1)
	{
		if(cur==0)
		{
			cout << "Phoebe" << endl;
			
		}
		else
		{
			cout << "Joey" << endl;
			
		}
		return true;

	}
	bool temp = false;
	//down
	if( x+1 < m)
	{
		temp = solve(m,n,k,x+1,y,cur^1);
		if(temp)
		{
			return true;
		}
	}
	//right
	if(y+1 <n)
	{
		temp = solve(m,n,k,x,y+1,cur^1);
		if(temp)
		{
			return true;
		}
	}
	if(x+k <m && y+k < n)
	{
		temp = solve(m,n,k,x+k,y+k,cur^1);
		if(temp)
		{
			return true;
		}
	}
	return false;

}


int main()
{
	int t,k;
	cin >> t >> k;
	while(t--)
	{
		int m,n;
		cin >> m >> n;
		bool temp = solve(m,n,k,0,0,0);
	}
	return 0;
}