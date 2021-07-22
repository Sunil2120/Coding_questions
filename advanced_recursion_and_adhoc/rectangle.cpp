#include<bits/stdc++.h>
using namespace std;



bool compare( pair<int,int> p1 , pair<int,int> p2)
{
	return p1.first > p2.first;
}
int main()
{
	int n;
	cin >> n;
	int maxi_x=0;
	int maxi_y=0;
	int area = 0;
	vector< pair<int,int> > arr;
	for(int i=0;i<n;i++)
	{
		int l,b;
		cin >> b >> l;
		b=b/2;
		l=l/2;
		if(l > maxi_y)
		{
			maxi_y = l;
		}
		if(b > maxi_x)
		{
			maxi_x = b;
		}
		arr.push_back(make_pair(l,b));
	}

	sort(arr.begin(),arr.end(),compare);
	area = arr[0].first* arr[0].second;
	for(int i=1;i<n;i++)
	{
		if(arr[i].second > arr[i-1].second)
		{
			int breadth = arr[i].second  - arr[i-1].second;
			area =  area + ((arr[i].first)* breadth);
		}
	}
	cout << area* 4 << endl;
	return 0;


}