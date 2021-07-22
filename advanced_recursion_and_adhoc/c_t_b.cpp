#include<bits/stdc++.h>
using namespace std;




bool check(int n,int m)
{
	int total = n;
	int left,a,b;
	if(n-m < 0)
	{
		left = 0;
		a = n;
	}
	else
	{
		left = n - m;
		a= m;
	}
	b = left/10;
	n = left - b;
	while(n > 0)
	{
		if(n-m < 0)
		{
			left = 0;
			a += n;
		}
		else
		{
			left = n - m;
			a+=m;
		}
		b = left/10;
		n = left - b;
	}
	cout << "sum" << " " << a << endl;
	if(a >= total/2.0)
	{
		return true;
	}
	else
	{
		return false;
	}

}


int main()
{
	int n;
	cin >> n;

	int start = 1;
	int end = n;
	int value=0;
	while(start <= end)
	{
		int mid = (start+end)/2;
		if(check(n,mid))
		{
			value = mid;
			end = mid -1;
		}
		else
		{
			start = mid+1;
		}
	}
	cout << value << endl;
	//cout << check(68,4) << endl;
	return 0;


}