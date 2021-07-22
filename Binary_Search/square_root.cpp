#include<bits/stdc++.h>
using namespace std;

float square_root(int n,int p)
{
	int low = 0;
	int  high = n;
	float ans=-1;
	while(low<=high)
	{
		int mid = low + (high-low)/2 ;
		if((mid*mid)==n)
		{
			ans = mid;
			break;
		}
		else if((mid*mid) > n)
		{
			high = mid-1;
		}
		else
		{
			// this may be our ans
			ans = mid;
			low = mid+1;
		}
	}
	float incr = 0;
	float div = 1;
	while(p--)
	{
		div = div/10;
		incr = div;
		while(ans*ans <= n)
		{
			ans+=incr;
		}
		ans = ans - incr;
	}
	return ans;
}


int main()
{
	float n;
	cin >> n;
	cout << square_root(n,3) << endl;
	return 0;
}