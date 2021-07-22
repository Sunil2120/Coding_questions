#include<bits/stdc++.h>
using namespace std;


int main()
{
	int max_=0;
	int min_=9999999;
	int n;
	int cost_1,cost_2;

	cin >> n >> cost_1 >> cost_2;
	int* arr = new int[n];
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
		if(arr[i] < min_)
		{
			min_ = arr[i];
		}
		else if(arr[i] > max_)
		{
			max_ = arr[i];
		}
	}
	// cout << min_ << endl;
	// cout << max_ << endl;
	int min_x=999;
	int inc=0;
	int dec=0;
	for(int k=min_;k<=max_;k++)
	{
		for(int i=0;i<n;i++)
		{
			if(arr[i]!=k)
			{
				if(arr[i]<k)
				{
					inc+=(k-arr[i]);
				}
				else
				{
					dec+=(arr[i]-k);
				}

			}
		}
		int total = (dec*cost_1)+((inc-dec)*cost_2);
		if(total < min_x)
		{
			min_x = total;
		}
	}
	cout << min_x << endl;


}