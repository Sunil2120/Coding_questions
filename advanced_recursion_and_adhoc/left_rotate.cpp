#include<bits/stdc++.h>
using namespace std;



void rotate(int* arr,int n,int d)
{
	vector<int> temp;
	int s;
	for(int i=0;i<d;i++)
	{
		//cout << "temp" << arr[i] << endl;
		temp.push_back(arr[i]);
	}
	for(s=0;s<n-d;s++)
	{
		arr[s]=arr[s+d];
	}
	for(int i=0;i<d;i++)
	{
		arr[s]=temp[i];
		s++;
	}
	for(int i=0;i<n;i++)
	{
		cout << arr[i] << " ";
	}

	return ;

}

int main()
{
	int n;
	cin >> n;
	int d;
	
	int* arr = new int[n];
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
	}
	cin >> d;
	rotate(arr,n,d);
	cout << "-------" << endl;
	// for(int i=0;i<n;i++)
	// {
	// 	cout <<  arr[i] << endl;
	// }
	return 0;
}