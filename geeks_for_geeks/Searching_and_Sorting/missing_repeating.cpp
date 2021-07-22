int *findTwoElement(int *arr, int n) {
        
        int* res = new int[2];
        res[0]=-1;
        res[1]=-1;
        int MAX = n+1;
        int max_value = 0;
        for(int i=0;i<n;i++)
        {
            // i will go to arr[i]-1 index and add max value
            arr[(arr[i])%MAX-1]+=MAX;
        }
        for(int i=0;i<n;i++)
        {
            if((arr[i]/MAX)==0 && res[1]==-1)
            {
              res[1]=i+1;  
            }
            if((arr[i]/MAX) > max_value)
            {
                max_value = arr[i]/MAX;
                res[0]=i+1;
            }
        }
        return res;
        
    }