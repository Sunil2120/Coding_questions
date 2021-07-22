#include<bits/stdc++.h>
using namespace std;



void build(int* tree,vector<int>& arr,int start,int end,int tree_index)
{
	if(start==end)
	{
		tree[tree_index]=arr[start];
		return ;
	}
	int mid = start + (end-start)/2;
	build(tree,arr,start,mid,2*tree_index);
	build(tree,arr,mid+1,end,2*tree_index + 1);
	tree[tree_index]=tree[2*tree_index]+tree[2*tree_index + 1];
	return ;
}

void update(int* tree,int start,int end,int tree_index,int r1,int r2,int value)
{
	if(lazy[tree_index]!=0)
	{
		tree[tree_index]+=(end-start+1)*lazy[tree_index];
		if(start!=end)//not leaf node
		{
			lazy[2*tree_index]+=lazy[tree_index];
			lazy[2*tree_index + 1]+=lazy[tree_index];
		}
		lazy[tree_index]=0;
	}
	if(start >=r1 && end<= r2)
	{
		tree[tree_index] += (end-start+1)*value;
		if(start!=end)
		{
			lazy[2*tree_index]+=value;
			lazy[2*tree_index+1]+=value;
		}
		return ;
	}
	if(start > r2 || end < r1)
	{
		return ;
	}
	int mid = start + (end-start)/2;
	update(tree,start,mid,2*tree_index,r1,r2,value);
	update(tree,mid+1,end,2*tree_index+1,r1,r2,value);
	tree[tree_index]
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
	int* tree = new int[4*n];
	int* lazy = new int[4*n]();
	build(tree,arr,0,n-1,1);
	int m;
	cin >> m;

	return 0;
}