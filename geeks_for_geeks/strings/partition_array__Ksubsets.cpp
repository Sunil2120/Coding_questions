

//hint :
/**
same as backtracking
one important thing to note here
ex1 : {1},{},{}
ex2 : {},{1},{}
ex3 : {},{},{1}
ex1,ex2,ex3 are same
if(more than one empty sets)
    it's enough to put element in one empty set
    so it would reduce our function calls**/


class Solution{
  public:
  
    bool solve(int a[],int n,int k,vector<int>& sums,int index)
    {
        if(index==n)
        {
            for(int i=1;i<k;i++)
            {
                if(sums[i]!=sums[i-1])
                {
                    return false;
                }
            }
            return true;
        }
        int check = 0;
        for(int i=0;i<k;i++)
        {
            if(sums[i]==0 && check==1)
            {
                continue;
            }
            if(sums[i]==0)
            {
                check=1;
            }
            sums[i]+=a[index];
            if(solve(a,n,k,sums,index+1))
            {
                return true;
            }
            sums[i]-=a[index];
        }
        return false;
    }
    bool isKPartitionPossible(int a[], int n, int k)
    {
        
        vector<int> sums(k,0);
        return solve(a,n,k,sums,0);
        
    }
};