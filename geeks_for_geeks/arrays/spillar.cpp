#include <iostream>
using namespace std;


void solve2(int** arr,int x,int y,int m1,int n1,int& total)
{
	if(total==0)
	{
		return ;
	}
	for(int i=y;i<=n1;i++)
	{
		if(total==0)
		{
			return ;
		}
		cout << arr[x][i] << " ";
		total--;
	}
	for(int i=x+1;i<=m1;i++)
	{
		if(total==0)
		{
			return ;
		}
		cout << arr[i][n1] << " ";
		total--;
	}
	for(int i=n1-1;i>=y;i--)
	{
		if(total==0)
		{
			return ;
		}
		cout << arr[m1][i] << " ";
		total--;
	}
	for(int i=m1-1;i>=x+1;i--)
	{
		if(total==0)
		{
			return ;
		}
		cout << arr[i][y] << " ";
		total--;
	}
	solve2(arr,x+1,y+1,m1-1,n1-1,total);
	return ;
}

void solve(int** arr,int m,int n)
{
	int x = 0;
	int y = 0;
	int m1 = m-1;
	int n1 = n-1;
	int total = m*n;
	while(total!=0)
	{
		for(int i=y;i<=n1;i++)
		{
			if(total==0)
			{
				return ;
			}
			cout << arr[x][i] << " ";
			total--;
		}
		for(int i=x+1;i<=m1;i++)
		{
			if(total==0)
			{
				return ;
			}
			cout << arr[i][n1] << " ";
			total--;
		}
		for(int i=n1-1;i>=y;i--)
		{
			if(total==0)
			{
				return ;
			}
			cout << arr[m1][i] << " ";
			total--;
		}
		for(int i=m1-1;i>=x+1;i--)
		{
			if(total==0)
			{
				return ;
			}
			cout << arr[i][y] << " ";
			total--;
		}
		x+=1;
		y+=1;
		m1=m1-1;
		n1 = n1-1;
	}
	return ;
}

int main() {
	int t;
	cin >> t;
	while(t--)
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
    	int total = m*n;
    	solve2(arr,0,0,m-1,n-1,tota);
    	cout << endl;
    	for(int i=0;i<m;i++)
    	{
    	    delete[] arr[i];
    	}
    	delete[] arr;
	}
	return 0;
}