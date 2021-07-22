    

    // Time O(log(sum of all books)*(n))
    // space O(1)
    bool isPossible(int arr[],int n,int m,int value)
    {
        
        int j=0;
        int  sum=0;
        int students = 0;
        while(j<n)
        {
            if(arr[j] > value)
            {
                return false;
            }
            sum+=arr[j];
            if(sum > value)
            {
                students+=1;
                if(students > m)
                {
                    return false;
                }
                sum=arr[j];
            }
            j++;
        }
        students+=1;
        if(students > m)
        {
            return false;
        }
        return true;
    }
    //Function to find minimum number of pages.
    int findPages(int arr[], int n, int m) 
    {
        if(m > n)
        {
            return -1;
        }
        int sum = 0;
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
        }
        int low=0;// I am not giving any books to any student
        int high = sum;// giving all books to one student
        int ans=-1;
        while(low<=high)
        {
            int mid = low +(high-low)/2;
            if(isPossible(arr,n,m,mid)==true)
            {
                ans = mid;
                // i need minimum
                high = mid-1;
            }
            else
            {
                low = mid+1;// if it is not possible for mid then it is not possible for less than mid
            }
        }
        return ans;
    }