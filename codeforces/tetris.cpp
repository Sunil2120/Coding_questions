#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> col(n,0);
	int m;
	cin >> m;
	for(int i=0;i<m;i++)
	{
		int pos;
		cin >> pos;
		col[pos-1]+=1;
	}
	cout << *min_element(col.begin(),col.end()) << endl;
	return 0;
}