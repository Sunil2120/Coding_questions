   

//O(N) and O(1) space

// if a element counts more than N/2 times 
// count of other elements should be less than N/2;

// so the diff (count(candidate)-others) > 0 right
// so we will first find the candidate for majority element
// then we will check whether it can be majority element

    int majorityElement(vector<int>& nums) {
        
        int n = nums.size();
        int candidate = nums[0];
        int count = 1;
        for(int i=1;i<n;i++)
        {
            if(nums[i]==candidate)
            {
                count+=1;
            }
            else
            {
                count-=1;
                if(count==0)//this can't be my candidate
                {
                    candidate=nums[i];
                    count=1;
                }
            }
        }
        count = 0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==candidate)
            {
                count+=1;
            }
        }
        if(count >= (n/2))
        {
            return candidate;
        }
        return -1;
        
        
    }