// time O(nlogn)
// space O(1)

bool findPair(int arr[], int size, int n){
    
    sort(arr,arr+size);
    for(int i=0;i<size;i++)
    {
        //x-y = k
        // x = k+y;
        int req = n+arr[i];
        int low = i+1;
        int high = size-1;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            if(arr[mid]==req)
            {
                return true;
            }
            else if(req > arr[mid])
            {
                low = mid+1;
            }
            else
            {
                high = mid-1;
            }
        }
    }
    return false;
    
}