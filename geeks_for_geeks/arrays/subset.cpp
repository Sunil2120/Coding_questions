#include <bits/stdc++.h>
using namespace std;

// int main() {
// 	int t;
// 	cin >> t;
// 	while(t--)
// 	{
// 	    int m,n;
// 	    cin >> m >> n;
// 	   // int* arr1 = new int[m];
// 	   // int* arr2 = new int[n];
// 	   bool flag=false;
// 	    unordered_set<int> check;
// 	    for(int i=0;i<m;i++)
// 	    {
// 	        int value ;
// 	        cin >> value;
// 	        check.insert(value);
// 	    }
// 	    unordered_set<int> :: iterator it;
// 	    for(it=check.begin();it!=check.end();it++)
// 	    {
// 	    	cout << *it << " ";
// 	    }
// 	    cout << endl;
// 	    for(int i=0;i<n;i++)
// 	    {
// 	        int value;
// 	        cin >> value;
// 	        if(check.find(value)==check.end())
// 	        {
// 	            cout << "No" << endl;
// 	            flag = true;
// 	            break;
// 	        }
// 	    }
// 	    if(flag==false)
// 	    {
// 	        cout << "Yes" << endl;
// 	    }
// 	}
// 	return 0;
// }

// o(nlogn + mlog m)
int main()
{
	int m,n;
	cin >> m >> n;
	int* arr = new int[m];
	for(int i=0;i<m;i++)
	{
		cin >> arr[i];
	}
	int* arr1 = new int[n];
	for(int i=0;i<n;i++)
	{
		cin >> arr1[i];
	}
	sort(arr,arr+m);
	sort(arr1,arr1+n);
	// merging
	int count = 0;
	int i=0;
	int j=0;
	while(i<m && j < n)
	{
		if(arr[i]==arr1[j])
		{
			count+=1;
			i+=1;
			j+=1;
		}
		else if(arr[i] < arr1[j])
		{
			i+=1;
		}
		else
		{
			j+=1;
		}
	}
	if(count==n)
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}
	return 0;

}