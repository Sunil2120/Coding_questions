#include<bits/stdc++.h>
using namespace std;



int min_choco(int* arr,int n)
{
	int* output = new int[n];
	for(int i=0;i<n;i++)
	{
		output[i]=1;
	}

	for(int i=1;i<n;i++)
	{
		if(arr[i] > arr[i-1])
		{
			if(output[i] > output[i-1])
			{
				continue;
			}
			output[i] = output[i-1]+1;
		}
		else 
		{
			// cur child has less score than the previous child
			if(output[i-1] > output[i])
			{
				continue;
			}
			output[i-1]=output[i]+1;
			int k = i-1;
			while(k>=1)
			{
				if(arr[k] > arr[k-1])
				{
					if(output[k] > output[k-1])
					{
						continue;
					}
					output[k]+=1;
				}
				else 
				{
					if(output[k] < output[k-1])
					{
						continue;
					}
					output[k-1]+=1;
				}
				k--;
			}
		}
	}
	int sum=0;

	for(int i=0;i<n;i++)
	{
		sum+=output[i];
	}
	return sum;

}

int main()
{
	int n;
	cin >> n;
	int* arr = new int[n];
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
	}
	cout << min_choco(arr,n) << endl;
	return 0;
}