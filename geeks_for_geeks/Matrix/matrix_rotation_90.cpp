  
// time complexity O(3*(m*n) + (m*n))=>(3*transpose + reverse each row)
// time O(m*n)
// space O(1)

  void rotate(vector<vector<int>>& matrix) {
        
        for(int k=0;k<3;k++)
        {
            for(int i=0;i<matrix.size();i++)
            {
                for(int j=i;j<matrix[0].size();j++)
                {
                    int temp = matrix[i][j];
                    matrix[i][j]=matrix[j][i];
                    matrix[j][i]=temp;
                }
            }
            for(int i=0;i<matrix.size();i++)
            {
                for(int j=0;j<matrix[0].size();j++)
                {
                    cout << matrix[i][j] << " ";
                }
                cout << endl;
            }
        }
        for(int i=0;i<matrix.size();i++)
        {
            int j=0,k=matrix[0].size()-1;
            while(j<k)
            {
                int temp = matrix[i][j];
                matrix[i][j]=matrix[i][k];
                matrix[i][k]=temp;
                k--;
                j++;
            }
        }
        return;
        
    }