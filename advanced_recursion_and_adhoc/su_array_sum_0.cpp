#include<bits/stdc++.h>
using namespace std;


bool check(int* arr,int n)
{
	unordered_set<int> sumArr;
	int sum = 0;
	for(int i=0;i<n;i++)
	{
		sum+=arr[i];
		// if prefix sum is 0 or prefix repeats
		if(sum==0 || sumArr.find(sum)!=sumArr.end())
		{
			return true;
		}
		sumArr.insert(sum);
	}
	return false;
}


// time complexity o(n)

// there is a subarray  whose sum is equal to zero
// if prefix sum = 0 or prefix sum repeats
// if prefix sum repeats there is subarray whose sum is zero 
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		int* arr = new int[n];
		for(int i=0;i<n;i++)
		{
			cin >> arr[i];
		}
		if(check(arr,n))
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
		delete[] arr;
	}
	return 0;
}


// time complexity o(n2)
// int main()
// {
// 	int n;
// 	cin >> n;
// 	int* arr = new int[n];
// 	int sum = 0;
// 	for(int i=0;i<n;i++)
// 	{
// 		cin >> arr[i];
// 	}
// 	int check = 0;
// 	for(int i=0;i<n;i++)
// 	{
// 		sum = arr[i];
// 		if(sum == 0)
// 		{
// 			cout << "YES" << endl;
// 			check = 1;
// 			break;
// 		}
// 		for(int j= i+1;j<n;j++)
// 		{
// 			sum = sum + arr[j];
// 			if(sum == 0)
// 			{
// 				cout << "YES" << endl;
// 				check = 1;
// 				break;
// 			}
// 		}
// 		if(check==1)
// 		{
// 			break;
// 		}
// 	}
// 	if(check == 0)
// 	{
// 		cout << "NO" << endl;
// 	}
// 	return 0;
// }