#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--)
    {
        int n;
        cin >> n;
        int* arr = new int[n];
        int* check = new int[n]();
        for(int i=0;i<n-1;i++)
        {
            cin >> arr[i];
            check[arr[i]-1]=-1;
        }
        for(int i=0;i<n;i++)
        {
            if(check[i]==0)
            {
                cout << i+1 << endl;
                break;
            }
        }
        delete[] arr;
        delete[] check;
    }
	return 0;
}