#include<bits/stdc++.h>
using namespace std;

// O(logn)
bool isperfectsquare(int n)
{
	int low = 1;
	int high = n;
	while(low <= high)
	{
		int mid = low + (high-low)/2;
		if(mid*mid == n)
		{
			return true;
		}
		if( n > mid*mid )
		{
			low = mid+1;
		}
		else
		{
			high = mid-1;
		}
	}
	return false;

}

int main()
{
	int n;
	cin >> n;
	cout << isperfectsquare(n) << endl;
	return 0;
}