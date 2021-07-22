#include<bits/stdc++.h>
using namespace std;


vector<int> output(2,0);

void solve2(int* arr,int n,int index,int cur1,int cur2,int n1,int n2,int& min_value,int str1,int str2)
{

	
	
	if( (n1+n2)==n && (n1==(n/2) || (n2==(n/2))))
	{
		
		if(abs(cur1-cur2) < min_value)
		{
			min_value = abs(cur1-cur2);
			output[0]=str1;
			output[1]=str2;
		}
		return ;
	}

	if(index==n)
	{
		return ;
	}
	//exclude
	solve2(arr,n,index+1,cur1,cur2,n1,n2,min_value,str1,str2);
	//include
	int temp1 = str1;
	temp1 = temp1 | (1<< index) ;
	solve2(arr,n,index+1,cur1+arr[index],cur2,n1+1,n2,min_value,temp1,str2);
	int temp2 = str2;
	temp2 = temp2 | (1<< index);
	solve2(arr,n,index+1,cur1,cur2+arr[index],n1,n2+1,min_value,str1,temp2);
	return ;
}


void solve(int* arr,int n)
{
	int min_value = INT_MAX;
	solve2(arr,n,0,0,0,0,0,min_value,0,0);
	cout << output[0] << " " << output[1] << endl;
	int i=0;
	int cur = 1;
	vector<int> temp1;
	vector<int> temp2;
	while(i<n)
	{
		if((output[0] & (1<<i))!=0)
		{
			temp1.push_back(arr[i]);
		}
		else
		{
			temp2.push_back(arr[i]);
		}
		i++;
	}
	for(int i=0;i<temp1.size();i++)
	{
		cout << temp1[i] << " ";
	}
	cout << endl;
	for(int i=0;i<temp2.size();i++)
	{
		cout << temp2[i] << " ";
	}
	cout << endl;
	return ;
}
int main()
{
	int n;
	cin >> n;
	int* arr = new int[n];
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
	}
	solve(arr,n);
	return 0;
}