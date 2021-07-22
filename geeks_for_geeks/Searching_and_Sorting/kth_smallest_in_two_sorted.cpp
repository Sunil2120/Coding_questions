#include<bits/stdc++.h>
using namespace std;

// refer striver's video

/*

arr1 = [1,4,2,5,8]
arr2 = [3,7,10]
k=5
1,2,3,4,5||7,8,10
first k elements are less than remaining elements 
so we'll try to take k elements from both first and second array which are less than remaining elements
then max(of them) is our k'th smallest element
we would be applying binary search to reduce the time we'll apply binary search on array with minsize
*/

// Time O(log(min(n,m)))  // since we are applying bs on array with min elements
// space O(1)
int solve2(vector<int>& arr1,vector<int>& arr2,int n,int m,int k)
{
	if(k > (n+m))
	{
		return -1;
	}
	if(n==0)
	{
		return arr2[k-1];
	}
	else if(m==0)
	{
		return arr1[k-1];
	}
	// if m is greater than n
	if(m > n)
	{
		return solve2(arr2,arr1,m,n,k);
	}
	// here we are applying binary search on arr1(n < m)
	// in this case n is less then m
	// we would be applying binary search on arr1
	// if all elements  of arr2 are included we should include atleast (k-m) in arr1 to get k elements
	// if m is equal to k then we should include zero elements from arr1 so low = 0 (total will be k elements)
	int low = max(0,k-m);

	// if n is greater than k, we will include max k elements from arr1
	// if k is greater than n we will include max n elements from arr1
	// remaining elements i,e(k-n) we will take that from arr2
	int high = min(n,k);

	while(low<=high)
	{
		int cut1 = (low+high)>>1;// we are including cut1 elements from arr1
		int cut2 = k-cut1;// we are includig remaining (k-cut1) elements from arr2;
		int l1 = cut1==0?INT_MIN:arr1[cut1-1];
		int l2 = cut2==0?INT_MIN:arr2[cut2-1];
		int r1 = cut1==n?INT_MAX:arr1[cut1];
		int r2 = cut2==m?INT_MAX:arr2[cut2];
		// we are comparing l1 and r2,   l2 and r1
		// because since the arrays are sorted l1 <= r1 and l2<=r2
		if(l1 <= r2 && l2 <= r1)
		{
			return max(l1,l2);
		}
		if(l1 > r2)
		{
			high = cut1-1;//go left because we don't want l1
		}
		else// l2 > r1
		{
			low = cut1+1;// go right because we want r1
		}

	}
	return -1;

}

// Time O(k) and Space O(1)
int solve1(vector<int>& arr1,vector<int>& arr2,int n,int m,int k)
{
	if(k > (n+m))
	{
		return -1;
	}
	if(n==0)
	{
		return arr2[k-1];
	}
	else if(m==0)
	{
		return arr1[k-1];
	}
	int i=0;
	int j=0;
	int count=0;
	while(i<n && j<m)
	{
		if(arr1[i] <= arr2[j])
		{
			count+=1;
			if(count==k)
			{
				return arr1[i];
			}
			i+=1;
		}
		else
		{
			count+=1;
			if(count==k)
			{
				return arr2[j];
			}
			j+=1;
		}
	}
	while(i<n)
	{
		count+=1;
		if(count==k)
		{
			return arr1[i];
		}
		i++;
	}
	while(j<m)
	{
		count+=1;
		if(count==k)
		{
			return arr2[j];
		}
		j++;
	}
	return -1;
}

int main()
{
	int n,m;
	cin >> n >> m;
	vector<int> arr1(n);
	vector<int> arr2(m);
	for(int i=0;i<n;i++)
	{
		cin >> arr1[i];
	}
	for(int j=0;j<m;j++)
	{
		cin >> arr2[j];
	}
	int k;
	cin >>k;
	cout << solve1(arr1,arr2,n,m,k) << endl;
	cout << solve2(arr1,arr2,n,m,k) << endl;
	return 0;
}