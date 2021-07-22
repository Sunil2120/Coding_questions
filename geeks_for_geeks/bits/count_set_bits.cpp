#include<bits/stdc++.h>
using namespace std;


int main()
{
	int n;
	cin >> n;
	int count = 0;
	while(n!=0)
	{
		int rmsb = n&-n;
		n = n - (rmsb);
		count+=1;
	}
	cout << count << endl;
	return 0;
}