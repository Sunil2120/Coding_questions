#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("sitin.txt","r",stdin);
	freopen("sitout.txt","w",stdout);
	int r,c;
	cin >> r >> c;
	int p;
	cin >> p;
	if( p <= r*c)
	{
		cout << p << " " << 0 << endl;
	}
	else
	{
		cout << r*c << " " << p-(r*c) << endl;
	}
	return 0;
}