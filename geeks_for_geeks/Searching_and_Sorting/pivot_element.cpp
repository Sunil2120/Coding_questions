class Solution {
public:
    
    int findPivot(vector<int>& nums,int low,int high)
    {
        int n = nums.size();
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            if(mid+1 < n && nums[mid+1] < nums[mid])
            {
                return mid+1;
            }
            if(mid-1>=0 && nums[mid-1] > nums[mid])
            {
                return mid;
            }
            if(nums[high] >= nums[mid])
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
    
    int bs(vector<int>& arr,int low,int high,int target)
    {
        int n = arr.size();
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            if(arr[mid]==target)
            {
                return mid;
            }
            else if(target > arr[mid])
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
    int search(vector<int>& nums, int target) {
        
        int pivot = findPivot(nums,0,nums.size()-1);
        cout << pivot << endl;
        if(pivot!=-1)
        {
            int left = bs(nums,0,pivot-1,target);
            if(left!=-1)
            {
                return left;
            }
            return bs(nums,pivot,nums.size()-1,target);
        }
        return bs(nums,0,nums.size()-1,target);
        
    }
};