 // using quick sort approach
// we can do it using heap approach just like in array

 int findpivot(vector<int>& arr,int low,int high)
    {
        int count = 0;
        for(int i=low+1;i<=high;i++)
        {
            if(arr[i] < arr[low])
            {
                count+=1;
            }
        }
        int index = low+count;
        swap(arr[low],arr[index]);
        int i=low;
        int j=high;
        while(i<j &&  i<index && j> index)
        {
            if(arr[i] >= arr[index] && arr[j] < arr[index])
            {
                swap(arr[i],arr[j]);
                i++;
                j--;
                continue;
            }
            if(arr[i] < arr[index])
            {
                i++;
            }
            if(arr[j] >= arr[index])
            {
                j--;
            }
            
        }
        return index;
        
    }
    int QuickSort(vector<int>& arr,int k,int low,int high)
    {
        if(low <= high)
        {
            int pivot = findpivot(arr,low,high);
            if(pivot==(k-1))
            {
                return arr[pivot];
            }
             int left = QuickSort(arr,k,low,pivot-1);
            if(left!=-1)
                return left;
            
            int right = QuickSort(arr,k,pivot+1,high);
            if(right!=-1)
            {
                return right;
            }
        }
        return -1;
        
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> arr(m*n);
        int h=0;
        int output = -1;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                arr[h]=matrix[i][j];
                h++;
            }
        }
         return QuickSort(arr,k,0,arr.size()-1);
        
        
    }