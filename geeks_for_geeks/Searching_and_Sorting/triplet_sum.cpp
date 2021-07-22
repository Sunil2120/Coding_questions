
//Time O(n^2) space O(1)

long long countTriplets(long long arr[], int n, long long sum)
	{
	    long long output=0;
	    sort(arr,arr+n);
	    for(int i=0;i<=n-3;i++)
	    {
	        int l=i+1;
	        int r=n-1;
	        int target = sum - arr[i];
	        while(l<r)
	        {
	            int k = arr[l]+arr[r];
	            if(k >= target)
	            {
	                r--;
	            }
	            else
	            {
	                output+=(r-l);
	                l++;
	            }
	            
	        }
	    }
	    return output;
	}
