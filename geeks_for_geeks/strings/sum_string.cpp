#include <iostream>
#include <string>
using namespace std;
//int s
bool solve(string input)
{
  cout << input << endl;
  if(input.size()==0)
  {
    return true;
  }
  //12243660
  for(int j=input.size()-1;j>=0;j--)
  {
    int cur = stoi(input.substr(j));
    int len = input.size()-j;
    int temp = 0;
    for(int k=j-1;k>=0 && k>=(j-len);k--)
    {
        temp = stoi(input.substr(k,j-1-k+1));
        if(temp <= cur)
        {
          
            int required = cur-temp;
            int temp2=0;
            int l = k-1;
            while(temp2<required && l>=0)
            {
              temp2=stoi(input.substr(l,k-1-l+1));
              l--;
            }
            
            if(temp2==required)
            {
              cout<<temp2<<endl;
              if(l<0)
              {
                 return true;
              }
              
              bool check = solve(input.substr(0,j));
              if(check)
              {
                return true;
              }
            }
            
        }
        else
        {
          break;
        }
 
      
    }
  
   }
  
   return false;
  
  
}

int main()
{
    string input;
    cin >> input;
    if(solve("123456787"))
    {
      cout << "sum-string" << endl;
    }
    else
    {
      cout << "Not" << endl;
    }
  return 0;
}
