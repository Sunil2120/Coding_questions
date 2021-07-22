#include<iostream>
#include<string>
#include<cmath>
using namespace std;
const long long mod=1e9+7;
int main()
{
    string s;
    cin>>s;
    long long sum=1,ans=0;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='J')
        {
            sum*=2;
            sum%=mod;
        }
        else
        {
            ans+=sum-1;
            ans%=mod;
        }
    }
    cout<<ans<<endl;
    return 0;
} 