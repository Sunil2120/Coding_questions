    

// O(n) and O(n)
    vector<int> countBits(int n) {
        vector<int> res(n+1);
        res[0]=0;
        for(int i=1;i<=n;i++)
        {
            res[i]=res[(i)&(i-1)]+1;
        }
        return res;
        
    }