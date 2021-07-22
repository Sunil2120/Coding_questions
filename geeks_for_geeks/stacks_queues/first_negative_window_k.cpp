#include<bits/stdc++.h>
using namespace std;


void solve(vector<int>& arr,int n,int k)
{
	if(k > n)
	{
		return ;
	}
	queue<int> Q;
	queue<int> negatives;
	int rear = 0;
	int k1 = k;
	while(k-- && rear < n)
	{
		if(arr[rear] < 0)
		{
			negatives.push(arr[rear]);
		}
		Q.push(arr[rear]);
		rear+=1;
	}
	vector<int> output;
	while(Q.size()==k1)
	{
		negatives.size()==0?output.push_back(0):output.push_back(negatives.front());
		if(negatives.front() == Q.front())
		{
			negatives.pop();
		}
		Q.pop();
		if(rear < n)
		{
			Q.push(arr[rear]);
			if(arr[rear] < 0)
			{
				negatives.push(arr[rear]);
			}
			rear+=1;
		}
	}
	for(int i=0;i<output.size();i++)
	{
		cout << output[i] << " ";
	}
	cout << endl;
	return ;


}
int main()
{
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
	}
	int k;
	cin >> k;
	solve(arr,n,k);
	return 0;
}