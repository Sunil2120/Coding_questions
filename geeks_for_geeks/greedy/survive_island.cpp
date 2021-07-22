#include<bits/stdc++.h>
using namespace std;

// int ceil(float value)
// {

// }
// if we can survive first week we can survive coming weeks also
int main()
{
	float n,m,s;
	cin >> s >> n >> m;
	// worst case we will purchase for 6 days
	// and check we can survive or not
	// if we can survive in worst case we can survive in all cases
	if((6*n) >= (7*m))
	{
		int purchase_days = ceil((s*m)/(n));
		cout << "can survive" << " " << purchase_days << endl;
	}
	else
	{
		cout << "can't survive" << endl;
	}
	return 0;
}