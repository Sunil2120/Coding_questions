#include<bits/stdc++.h>
using namespace std;


// it is a adhoc problem no generalized answer
//codeforces div-2 683 by it
void solve(int n)
{
	cout << n << endl;
	for(int i=1;i<=n;i++)
	{
		cout << i << " ";
	}
	cout << endl;
	return;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		solve(n) ;
	}
	return 0;
}