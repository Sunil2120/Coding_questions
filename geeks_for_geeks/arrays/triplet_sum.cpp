#include<bits/stdc++.h>
using namespace std;

// o(n3)
bool solve(int* arr,int n,int sum)
{
	
	for(int i=0;i<n-2;i++)
	{
		for(int j=i+1;j<n-1;j++)
		{
			for(int k=j+1;k<n;k++)
			{
				if(sum==(arr[i]+arr[j]+arr[k]))
				{
					cout << arr[i] << " " << arr[j] << " " << arr[k] << endl;
					return true;
				}
			}
		}
	}
	return false;
}

bool two_pointers(int* arr,int n,int start,int& second,int& third,int k)
{
	int f = start;
	int l = n-1;
	while(f<l)
	{
		int sum = arr[f]+arr[l];
		if(sum==k)
		{
			second=f;
			third = l;
			return true;
		}
		else if(sum < k)
		{
			f+=1;
		}
		else
		{
			l-=1;
		}
	}
	second = -1;
	third = -1;
	return false;
}

// o(n2)
bool solve1(int* arr,int n,int sum)
{
	sort(arr,arr+n);
	for(int i=0;i<n-2;i++)
	{
		// fixing the element;
		// sum = arr[i]+x+y;
		// sum-arr[i]=x+y using two pointer we should find the x and y sums up to sum - arr[i]
		if(arr[i] > sum)
		{
			continue;
		}
		int value = sum - arr[i];
		int second=0;
		int third = 0;
		bool ans = two_pointers(arr,n,i+1,second,third,value);
		//cout << value << " " << ans << endl;
		if(ans)
		{
			cout << arr[i] << " " << arr[second] << " " << arr[third] << endl;
			return true;
		}
	}
	return false;
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
	int k;
	cin >> k;
	cout << solve1(arr,n,k) << endl;
	delete[] arr;
	return 0;
}