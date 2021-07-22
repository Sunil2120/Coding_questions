  
// time O(nlogn + n)
// space O(n)

    int solve(vector<int>& arr)
    {
        vector<int> temp = arr;
        sort(temp.begin(),temp.end());
        int min_ = INT_MAX;
        int max_ = INT_MIN;
        int start = 0;
        int cut = 0;
        for(int i=0;i<arr.size();i++)
        {
            min_ = min(min_,arr[i]);
            max_ = max(max_,arr[i]);
            if(temp[start]==min_ && temp[i]==max_)
            {
                cut+=1;
                start = i+1;
                min_ = INT_MAX;
                max_ = INT_MIN;
            }
        }
        return cut==0?1:cut;
    }
    int maxChunksToSorted(vector<int>& arr) {
        
        return solve(arr);
        
    }