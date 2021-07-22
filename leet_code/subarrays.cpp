#include<bits/stdc++.h>
using namespace std;


int solve(int* arr,int n,int k)
{
	if(n==0)
	{
		return 0;
	}
	int count = 0;
	int start = 0;
	int end = 0;
	int total = 0;
	for(int i=0;i<n;i++)
	{
		total+=arr[i];
		 if(total < k && arr[i]==k)
            {
                count+=1;
                total = 0;
            }
		if(total >=k)
		{
			int suni = start;
			int temp = total;
			end = i;
			while(total > k && start < end)
			{
				total=total-arr[start];
				start++;
			}
			//cout <<start << " " << end << " " << total ;
			if(total==k)
			{
				count+=1;
				total = 0;
				start = end+1;
				continue;
			}
			if(total < k)
			{
				start = suni;
				total = temp;
			}
			cout << total << " " << count << endl;
			
		}
	}
	return count ;
}

int main()
{
	int n,k;
	cin >> n >> k;
	int* arr = new int[n];
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
	}
	cout << solve(arr,n,k) << endl;
}