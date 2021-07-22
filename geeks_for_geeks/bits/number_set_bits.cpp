    int setBits(int N) {
        
        
        int count = 0;
        while(N!=0)
        {
            int temp = N%2;
            N=N/2;
            if(temp==1)
            {
                count+=1;
            }
        }
        return count;
    }