#include<bits/stdc++.h>
using namespace std;



int main()
{
	int n,m;
	cin >> n >> m;
	int* arr = new int[n];
	string output;
	int latest = -1;
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
		arr[i]=arr[i]-1;
		output.push_back('0');
	}
	cout << output << endl;
	for(int i=0;i<n;i++)
	{
		output[arr[i]]='1';
		cout << output << endl;
		int j=0;
		while(j < n)
		{
			if(output[j]=='0')
			{
				j++;
			}
			else
			{
				int count = 0;
				while(output[j]=='1')
				{
					count++;
					j++;
				}
				if(count==m)
				{
					latest = i+1;
				}
				
			}
		}
		
	}
	cout << latest << endl;
	

}