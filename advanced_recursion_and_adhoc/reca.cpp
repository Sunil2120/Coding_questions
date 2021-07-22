#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int max_x =0;
	int* arr = new int[200000]();
	for(int i=0;i<n;i++)
	{
		int x,y;
		cin >> x >> y;
		if(x > max_x)
		{
			max_x=x;
		}
		if(arr[x/2] < y)
		{
			arr[x/2]= y;
		}
	}
	int area = 0;

	for(int i=(max_x/2) -1;i>=0 ;i--)
	{
		if( i == (max_x/2) )
		{
			area+= arr[max_x/2];
		}
		else
		{
			if(arr[i] < arr[i+1])
			{
				area += arr[i+1];
			}
			else
			{
				area += arr[i];
			}
		}
	}

	cout << area << endl;


}