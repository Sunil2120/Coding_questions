//O(nlogn)
  int lengthOfLIS(vector<int>& nums) {
     
        
        vector<int> dp;
        for(int i=0;i<nums.size();i++)
        {
            auto it = lower_bound(dp.begin(),dp.end(),nums[i]);
            if(it==dp.end())//all elements are less than mine
            {
                dp.push_back(nums[i]);
            }
            else
            {
                // my cur dp size is the largest inc subsequnce size
                int index = it - dp.begin();
                dp[index]=nums[i];
            }
        }
        return dp.size();
    }