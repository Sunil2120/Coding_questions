
// Time is sort(O(nlogn + n))
// Space is O(n+n)=>O(2*n)

class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    
	    vector<int> temp=nums;
	    int n = nums.size();
	    unordered_map<int,int> hash;
	    for(int i=0;i<n;i++)
	    {
	        hash[nums[i]]=i;
	    }
	    sort(temp.begin(),temp.end());
	    int count =0;
	    for(int i=0;i<n;i++)
	    {
	        if(temp[i]==nums[i])
	        {
	            continue;
	        }
	        int index = hash[temp[i]];
	        if(index!=i)
	            count+=1;
	        swap(nums[i],nums[index]);
	        hash[nums[i]]=i;
	        hash[nums[index]]=index;
	        
	    }
	    return count;
	    
	   
	}
};