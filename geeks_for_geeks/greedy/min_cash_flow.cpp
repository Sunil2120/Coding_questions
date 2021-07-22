#include<bits/stdc++.h>
using namespace std;
// our ultimate goal is to reduce net amount of all people to zero
//https://www.geeksforgeeks.org/minimize-cash-flow-among-given-set-friends-borrowed-money/

int getmin(vector<int>& net_amount,int n)
{
	int index = -1;
	int min_value = INT_MAX;
	for(int i=0;i<n;i++)
	{
		if(net_amount[i] < min_value)
		{
			min_value = net_amount[i];
			index = i;
		}
	}
	return index;
}

int getmax(vector<int>& net_amount,int n)
{
	int index = -1;
	int max_value = INT_MIN;
	for(int i=0;i<n;i++)
	{
		if(net_amount[i] > max_value)
		{
			max_value = net_amount[i];
			index = i;
		}
	}
	return index;
}
void solve2(vector<int>& net_amount,int n)
{
	//get max_deb and max_cred
	int maxDeb = getmin(net_amount,n);
	int maxCre = getmax(net_amount,n);
	if(net_amount[maxDeb]==0 && net_amount[maxCre]==0)
	{
		return ;//all people cash has been settled
	}
	int amount = min(-1*net_amount[maxDeb],net_amount[maxCre]);
	cout << maxDeb + 1 << " to " << maxCre + 1 << " " << amount << endl;
	net_amount[maxCre]-=amount;// if we subtract amount reduces to zero
	net_amount[maxDeb]+=amount;// if we add amount reduces to zero
	solve2(net_amount,n);
}

void solve(int** graph,int n)
{
	vector<int> net_amount(n,0);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			//net amount to total credits - total debts
			net_amount[i]+=(graph[j][i]-graph[i][j]);
		}
	}
	for(int i=0;i<n;i++)
	{
		cout << net_amount[i] << " ";
	}
	cout << endl;
	solve2(net_amount,n);
	return ;
}


int main()
{
	int n;
	cin >> n;
	int** graph = new int*[n];
	for(int i=0;i<n;i++)
	{
		graph[i]=new int[n];
		for(int j=0;j<n;j++)
		{
			graph[i][j]=0;
		}
	}
	int k;
	cin >> k;
	for(int i=0;i<k;i++)
	{
		int a,b,c;
		cin >> a >> b >> c;
		graph[a-1][b-1]=c;
	}
	solve(graph,n);
	return 0;
}