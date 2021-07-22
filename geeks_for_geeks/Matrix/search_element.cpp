    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int ans=-1;
        int m = matrix.size();
        int n = matrix[0].size();
        int low = 0;
        int high = m-1;
        while(low <= high)
        {
            int mid = (low+high)/2;
            if(matrix[mid][0]<=target)//this can be my answer
            {
                ans = mid;
                low=mid+1;
            }
            else
            {
                high = mid-1;
            }
           
        }
        cout << ans << endl;
        if(ans==-1)
        {
            return false;
        }
        if(matrix[ans][0]==target)
        {
            return true;
        }
        
        low = 0;
        high = n-1;
        while(low<=high)
        {
            int mid = (low+high)/2;
            if(matrix[ans][mid]==target)
            {
                return true;
            }
            if(matrix[ans][mid]<target)
            {
                low=mid+1;
            }
            else
            {
                high = mid-1;
            }
        }
        return false;
        
    }