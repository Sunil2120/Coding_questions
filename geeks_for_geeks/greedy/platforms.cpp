int findPlatform(int arr[], int dep[], int n)
{
	sort(arr,arr+n);// sort arrival time
	sort(dep,dep+n);// sort departure time
	int needed_plat = 1;// initially one platform needed
	int max_plat = 1;// initially one platform needed
	int i=1;// for arrival(one train has already arrived so it's pointing to next one)
	int j=0;// for departure
	while(i<n && j<n)
	{
	    if(arr[i] <= dep[j])//one train is already present we need extra platform
	    {
	        i+=1;
	        max_plat+=1;
	    }
	    else// train stationed leaves so  we'll decrement the platforms
	    {
	        j+=1;
	        max_plat-=1;
	    }
	    if(max_plat > needed_plat)// max platforms needed at any point of time
	    {
	        needed_plat=max_plat;
	    }
	}
	return needed_plat;
}