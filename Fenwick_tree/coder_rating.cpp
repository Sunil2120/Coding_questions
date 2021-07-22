#include<bits/stdc++.h>
using namespace std;


struct node
{
	int x;
	int y;
	int index;

};

bool compare(node a,node b)
{
	if(a.x==b.x)
	{
		return a.y < b.y;
	}
	return a.x < b.x;
}


int query(int* BIT,int value)
{
	int sum = 0;
	for(int i=value;i>0;i-=(i&(-i)))
	{
		sum+=BIT[i];
	}
	return sum;
}


void update(int* BIT,int index)
{
	for(int i=index;i<=100000;i+=(i&(-i)))
	{
		BIT[i]++;
	}
	return ;
}

int main()
{
	int n;
	cin >> n;
	node* input = new node[n];
	for(int i=0;i<n;i++)
	{
		cin >> input[i].x >> input[i].y;
		input[i].index = i;
	}
	// sorting based on x
	sort(input,input+n,compare);
	int* ans = new int[n];
	int* BIT = new int[100001]();// storing y;
	for(int i=0;i<n;i++)
	{
		ans[input[i].index]=query(BIT,input[i].y);
		update(BIT,input[i].y);
	}
	for(int i=0;i<n;i++)
	{
		cout << ans[i] << endl;
	}
	return 0;

}