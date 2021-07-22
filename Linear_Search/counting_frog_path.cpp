#include<bits/stdc++.h>
using namespace std;


int solve(int x,int y,int s,int t)
{
	// first we will check whether it can reach the square or not
	int value = x+y;// for will take exactly x+y time to reach position x+y from the origin.
	// now we will check the all the points in the square
	int count = 0;
	for(int i=x;i<=x+s;i++)
	{
		for(int j=y;j<=y+s;j++)
		{
			// we will check whether the current point is reachable or not
			if(i+j <= t)
			{
				count+=1;
			}
		}
	}
	return count;
}


int main()
{
	int x,y,s,t;
	cin >> x >> y >> s >> t;
	cout << solve(x,y,s,t) << endl;
	return 0;
}