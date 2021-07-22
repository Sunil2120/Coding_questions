
// an element is called pick element if it is greater then it's neighbours
class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        
       
        int n = arr.size();
        
        int low = 0;
        int high = arr.size()-1;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            
            if(mid-1>=0 && mid+1 < n )
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
            if(mid-1 >=0 && arr[mid-1]>arr[mid])
            {
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }
        return -1;
        
    }
};