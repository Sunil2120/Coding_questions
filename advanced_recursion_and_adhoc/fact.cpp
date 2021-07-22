#include <bits/stdc++.h>
using namespace std;

string factorial(int n)
{
    string* arr = new string[n+1];
    arr[0]="1";
    arr[1]="1";
    for(int i=2;i<=n;i++)
    {
        arr[i] = to_string(i*stoi(arr[i-1]));
    }
    string ans = arr[n];
    delete[] arr;
    return ans;
}

int main() {
	int t;
	cin >> t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    cout << factorial(n) << endl;
	}
	return 0;
}