#include<bits/stdc++.h>
using namespace std;

//O(m+n)

int solve2(int** arr,int m,int n)
{
	
	    int index = n-1;
    	int result = 0;
    	for(int i=0;i<n;i++)
    	{
    		if(arr[0][i]==1)
    		{
    			index=i;
    			break;
    		}
    	}
    	int max_=0;
    	int max_i=-1;
    	if(arr[0][index]==1)
    	{
    	    max_=(n-index);
    	    max_i=0;
    	}
    	for(int i=1;i<m;i++)
    	{
    	
    		if(arr[i][index]==0)
    		{
    			continue;
    		}
    	   int j= index;
            while(j>=0 && arr[i][j]==1)
    	    {
    	        j--;
    	    }
    	    j+=1;
    	    int n_z=(n-j);
    	    if(n_z>max_)
    	    {
    	        max_=n_z;
    	        max_i=i;
    	    }
    
    	}
    	return max_i;
}
//O(mlogn)
int solve(int** arr,int m,int n)
{
	int max_value = 0;
	int max_i = -1;
	for(int i=0;i<m;i++)
	{
		if(arr[i][0]==1)
		{
			return i;
		}
		//apply binary search
		int low = 0;
		int high = n-1;
		int ans = -1;
		while(low<=high)
		{
			int mid = (low+high)/2;
			if(arr[i][mid]==1)
			{
				ans = mid;
				high=mid-1;
			}
			else
			{
				low = mid+1;
			}
		}
		if(ans!=-1)
		{
			if((n-ans) > max_value)
			{
				max_value = (n-ans);
				max_i = i;
			}
		}
	}
	return max_i;
}

int main()
{
	int m,n;
	cin >> m >> n;
	int** arr = new int*[m];
	for(int i=0;i<m;i++)
	{
		arr[i]=new int[n]();
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin >> arr[i][j];
		}
	}
	cout << solve(arr,m,n) << endl;
	cout << solve2(arr,m,n) << endl;
	return 0;
}