#include<bits/stdc++.h>
using namespace std;


// Right most set bit =>   number & (two's compliment of number( ~number+1))
int main()
{
	int n;
	cin >> n;
	cout << n&(-n) << endl;
	return 0;
}