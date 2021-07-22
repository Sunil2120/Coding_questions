#include<bits/stdc++.h>
using namespace std;



long long merge(int a[],int left,int m,int right)
{
	int i=left;
	int j = m;
	int k=0;
	long long count = 0;
	int temp[right-left+1];
	while(i<m && j<=right)
	{
		if(a[i] <= a[j])
		{
			temp[k++]=a[i++];
		}
		else
		{
			count += (m-i);// length of left array - current index
			temp[k++] = a[j++];
		}
	}
	while(i<m)
	{
		temp[k++]=a[i++];
	}
	while(j<=right)
	{
		temp[k++]=a[j++];
	}
	for(int i=left,k=0;i<=right;i++,k++)
	{
		a[i]=temp[k];
	}
	//cout << count << endl;
	return count;
}


long long merge_sort(int a[],int left,int right)
{
	long long count =0;
	if(right > left)
	{
		int mid = (left+right)/2;
		long long count_l = merge_sort(a,left,mid);
		long long count_r = merge_sort(a,mid+1,right);
		long long c= merge(a,left,mid+1,right);
		count = count_r + count_l + c;
		return count;
	}
	return count;
	
}
long long solve(int a[],int n)
{
	return merge_sort(a,0,n-1);
}

int main()
{
	int a[18]={4,2,3,56,32,0,4,2,33,1};
	cout << solve(a,10) << endl;
	return 0;
}