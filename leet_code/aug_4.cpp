#include<bits/stdc++.h>
using namespace std;

  bool isPowerOfFour(int n) {
        
      // bool first = (n>0);
      //   if(first==false)
      //   {
      //       // cout << "first" << endl;
      //       return false;
      //   }
        
      //   bool second = ((n&(n-1))==0);
      //   if(second==false)
      //   {
      //        //cout << "s" << endl;
      //       return false;
      //   }
      //    bool third = ((n & 0xAAAAAAAA)==0);
      //   if(third==false)
      //   {
      //        //cout << "t" << endl;
      //       return false;
      //   }
        return ((n!=0) && ((n&(n-1))==0) && ((n & 0xAAAAAAAA)==0) );
        //return true;
        
    }


int main()
{
    int n;
    cin >> n;
    cout << isPowerOfFour(n) << endl;
}