#include<bits/stdc++.h>
using namespace std;
int main() {

	// Write your code here
    int n;
    cin >> n;
    int target;
    cin >> target;
    int* arr=new int[n];
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    int sum=0;
    int k,h;
    int s=0;
    int a=0;
    for(k=0;k<n;k++)
    {
        sum+=arr[k];
        if(sum==target)
        {
            cout << "true" << endl;
            cout << arr[k];
            exit(0);
        }
        for(h=k+1;h<n;h++)
        {
            sum+=arr[h];
            if(sum==target)
            {
                cout << "true" << endl;
                a=h;

                break;   
            }
            
        }
        if(sum==target)
        {
            s=k;
            break;
        }
        else
        {
            sum=0;

        }
    }
    if(s==0 && a==0)
    {
        cout << "false" << endl;
    }
    else
    {
        for(int i=s;i<=a;i++)
        {
            cout << arr[i] << " ";
        }
    }
    

    return 0;
    
}