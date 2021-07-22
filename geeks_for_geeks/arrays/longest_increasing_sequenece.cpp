// using dp we can do it in O(N*N) space O(N)
// we can optimize it O(N*logN) space O(N)

// refer striver's video(take u forward)
int removeStudents(int H[], int N) {
       
       vector<int> dp;
       for(int i=0;i<N;i++)
       {
           if(dp.size()==0 || dp.back() < H[i])
           {
               dp.push_back(H[i]);
           }
           else
           {
               int low = 0;
               int high = dp.size()-1;
               int index = -1;
               while(low<=high)
               {
                   int mid = low + (high-low)/2;
                   if(dp[mid]>=H[i] )
                   {
                       index = mid;
                       high = mid-1;
                   }
                   else
                   {
                       low = mid+1;
                   }
               }
               if(index!=-1)
               {
                   dp[index]=H[i];
               }
           }
       }
       return N-dp.size();
    }