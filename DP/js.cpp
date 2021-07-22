#include<bits/stdc++.h>
using namespace std;


void solve(int n,int k,int x,int* arr)
{
	int* bucket = new int[1000+1]();
	for(int i=0;i<n;i++)
	{
		bucket[arr[i]]+=1;

	}
	int* temp = new int[1000+1]();
	int count = 0;
	for(int i=0;i<k;i++)
	{
		for(int j=0;j<=1000;j++)
		{
			
			count+=bucket[j];
			if(bucket[j]==0)
			{
				continue;
			}
			if(bucket[j]%2==0)
			{
				temp[j^x]+=bucket[j]/2;
				temp[j]+=bucket[j]/2;
			}
			else
			{
				int h = count - 1 - bucket[j];
				if( h < 0)
				{
					temp[j]+=bucket[j]/2;
					temp[j^x] += bucket[j] - (bucket[j]/2);

				}
				else if(h%2==0)
				{
					temp[j^x]+=bucket[j]/2;
					temp[j]+= bucket[j] - (bucket[j]/2);
				}
				else
				{
					temp[j]+=bucket[j]/2;
					temp[j^x] += bucket[j] - (bucket[j]/2);
				}

			}
		}

		for(int i=0;i<=1000;i++)
		{
			bucket[i]=temp[i];
			temp[i]=0;
		}
		count = 0;
	}


	int ma=0;
	int mi=0;
	for(int i=0;i<=1000;i++)
	{
		if(bucket[i] > 0)
		{
			mi = i;
			break;
		}
	}

	for(int i=1000;i>=0;i--)
	{
		if(bucket[i] > 0)
		{
			ma = i;
			break;
		}

	}

	cout << ma << " " << mi << endl;
	return ;
}

int main()
{
	int n,k,x;
	cin >> n >> k >> x;
	int* arr = new int[n];
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
	}
	solve( n, k,x, arr);
	return 0;
}