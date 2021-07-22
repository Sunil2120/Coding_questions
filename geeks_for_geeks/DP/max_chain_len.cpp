// Maximum Length Chain of Pairs | DP-20
// Last Updated: 22-10-2019
// You are given n pairs of numbers. 
// In every pair, the first number is always smaller than the second number.
//  A pair (c, d) can follow another pair (a, b) if b < c. Chain of pairs can be formed in this fashion. 
// Find the longest chain which can be formed from a given set of pairs.

// This problem is a variation of standard Longest Increasing Subsequence problem.
//  Following is a simple two step process.
// 1) Sort given pairs in increasing order of first (or smaller) element. 
// Why do not need sorting? Consider the example {{6, 8}, {3, 4}} to understand the need of sorting.
//  If we proceed to second step without sorting, we get output as 1. But the correct output is 2.
// 2) Now run a modified LIS process where we compare the second element of already finalized LIS with the first element of 
// new LIS being constructed.

// bool compare(struct val a,struct val b)
// {
//     return a.first < b.first;
// }

// int maxChainLen(struct val p[],int n)
// {
//     sort(p,p+n,compare);
//     vector<int> dp;
//     dp.assign(n,0);
//     int max_value;
//     for(int i=0;i<n;i++)
//     {
//         max_value = 0;
//         for(int j=i-1;j>=0;j--)
//         {
//           if(p[i].first > p[j].second)  
//           {
//               max_value = max(max_value,dp[j]);
//           }
//         }
//         dp[i]=max_value+1;
//     }
//     max_value = 0;
//     for(int i=0;i<n;i++)
//     {
//         max_value = max(max_value,dp[i]);
//     }
//     return max_value;
// }