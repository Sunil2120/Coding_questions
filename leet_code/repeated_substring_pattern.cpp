#include<bits/stdc++.h>
using namespace std;

bool repeatedSubstringPattern(string s)
{       
    int n = s.size();
    for(int i=2;i<=n;i++)
    {
        if((n%i) !=0)// it doesnot divide the string into equal parts.
        {
            continue;
        }
        int len = n/i;
        string temp = "";
        for(int j=0;j<n/len;j++)
        {
           temp = temp + s.substr(0,len); 
        }
        if(temp==s)
        {
            return true;
        }
        
    }
    return false;
        
}

int main()
{
    string s;
    cin >> s;
    cout << repeatedSubstringPattern(s) << endl;
    return 0;
}
