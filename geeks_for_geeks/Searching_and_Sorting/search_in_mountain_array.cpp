/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    
    int findPeak(MountainArray &arr)
    {
        int n = arr.length();
        int low = 0;
        int high = n-1;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            if(mid-1>=0 && mid+1 < n)
            {
                if(arr.get(mid) > arr.get(mid-1) && arr.get(mid) > arr.get(mid+1))
                {
                    return mid;
                }
            }
            else if(mid-1>=0)
            {
                if(arr.get(mid) > arr.get(mid-1))
                {
                    return mid;
                }
            }
            else if(mid+1 < n)
            {
                if(arr.get(mid) > arr.get(mid+1))
                {
                    return mid;
                }
            }
            else
            {
                return mid;
            }
            if(mid+1 < n && arr.get(mid) < arr.get(mid+1))
            {
                low = mid+1;
            }
            else
            {
                high = mid;
            }
        }
        return -1;
    }
    
    int BS(MountainArray &arr,int low,int high,int target)
    {
        int n = arr.length();
        int ans=-1;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            int value = arr.get(mid);
            if(value==target)
            {
                ans = mid;
                high = mid-1;
            }
            else if(target < value)
            {
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }
        return ans;
    }
    
    int BS2(MountainArray &arr,int low,int high,int target)
    {
        int n = arr.length();
        int ans=-1;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            int value = arr.get(mid);
            if(value==target)
            {
                ans = mid;
                high = mid-1;
            }
            else if(target < value)
            {
                low = mid+1;
            }
            else
            {
                high = mid-1;
            }
        }
        return ans;
    }
   
   
    int findInMountainArray(int target, MountainArray &mountainArr) {
        
        int peak = findPeak(mountainArr);
        cout << peak << endl;
        
        int left = BS(mountainArr,0,peak,target);
        if(left!=-1)
        {
            return left;
        }
        int right = BS2(mountainArr,peak+1,mountainArr.length()-1,target);
        return right;
    }
};