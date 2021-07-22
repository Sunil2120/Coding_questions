

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        
        int n = arr.size();
        int low = 0;
        int high = n-1;
        while(low<=high)
        {
            int mid = low +(high-low)/2;
            if(mid-1>=0 && mid+1<n)
            {
                if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1])
                {
                    return mid;
                }
            }
            else if(mid-1>=0)
            {
                if(arr[mid] > arr[mid-1])
                {
                    return mid;
                }
            }
            else if(mid+1 < n)
            {
                if(arr[mid] > arr[mid+1])
                {
                    return mid;
                }
            }
            else
            {
                return mid;
            }
            if(mid+1 < n && arr[mid] < arr[mid+1])
            {
                low = mid+1;
            }
            else
            {
                high = mid-1;
            }
        }
        return -1;
        
    }
};