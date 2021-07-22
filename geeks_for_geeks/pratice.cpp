#include <iostream>

using namespace std;


int solve(string input,int k)
{
  
  cout << "hello" << endl;
  int n = input.size();
  
  if(k > n)
  {
    return -1;
  }
  if(n==1 && k==1)
  {
    if(input[0]=='0')
    {
      return 0;
    }
    else
    {
      return 1;
    }
  }
  int** dp = new int*[n];
  for(int i=0;i<n;i++)
  {
    dp[i]=new int[n]();
  }
  for(int g=0;g<n;g++)
  {
  
    for(int i=0,j=g;j<n;i++,j++)
    {
      if(g==0)
      {
        if(input[i]==input[j] && input[i]=='1')
        {
          dp[i][j]+=1;
        }
      }
      else if(g==1)
      {
        if(input[i]=='1')
        {
          dp[i][j]+=1;
        }
        if(input[j]=='1')
        {
          dp[i][j]+=1;
        }
      }
      else
      {
        dp[i][j]+=dp[i-1][j-1];
        if(input[i]=='1')
        {
          dp[i][j]+=1;
        }
        if(input[j]=='1')
        {
          dp[i][j]+=1;
        }
      }
    }
  }
  cout<<"fun"<<endl;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      cout << dp[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}