#include<bits/stdc++.h>
using namespace std;



void solve(int** arr,int m,int n,int x,int y,vector<int>& temp)
{
	if(x >= m  || y>=n)
	{
		return ;
	}
	if(x==m-1 && y==n-1)
	{
		temp.push_back(arr[x][y]);
		for(int i=0;i<temp.size();i++)
		{
			cout << temp[i] << " ";
		}
		cout << endl;
		temp.pop_back();
		return ;
	}
	temp.push_back(arr[x][y]);
	//right
	solve(arr,m,n,x,y+1,temp);

	//down
	solve(arr,m,n,x+1,y,temp);
	temp.pop_back();
	return ;

}

int main()
{
	int m,n;
	cin >> m >> n;
	int** arr = new int*[m];
	for(int i=0;i<m;i++)
	{
		arr[i]=new int[n];
		for(int j=0;j<n;j++)
		{
			cin >> arr[i][j];
		}
	}
	vector<int> temp;
	solve(arr,m,n,0,0,temp);
	return 0;
}