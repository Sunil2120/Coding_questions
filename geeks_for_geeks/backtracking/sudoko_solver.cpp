   
    bool isSafe(int grid[N][N],int k,int x,int y)
    {
        //col
        for(int i=0;i<N;i++)
        {
            if(grid[i][y]==k)
            {
                return false;
            }
        }
        //row
        for(int i=0;i<N;i++)
        {
            if(grid[x][i]==k)
            {
                return false;
            }
        }
        //box
        x=x/3;
        y=y/3;
        x=x*3;
        y=y*3;
        for(int i=x;i<N && i<x+3;i++)
        {
            for(int j=y;j<N && j<y+3;j++)
            {
                if(grid[i][j]==k)
                {
                    return false;
                }
            }
        }
        return true;
    }
    //Function to find a solved Sudoku. 
    bool SolveSudoku(int grid[N][N])  
    { 
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                if(grid[i][j]==0)//empty
                {
                    
                    for(int k=1;k<=9;k++)
                    {
                        if(isSafe(grid,k,i,j)==true)
                        {
                            grid[i][j]=k;
                            bool temp = SolveSudoku(grid);
                            if(temp==true)
                            {
                                return true;
                            }
                            grid[i][j]=0;
                        }
                    }
                    if(grid[i][j]==0)
                    {
                        return false;
                    }
                }
            }
        }
      
        
        return true;
        
    
    }