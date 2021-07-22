#include<bits/stdc++.h>
using namespace std;



void build_tree(int* arr,int* tree,int start,int end,int tree_node)
{
	if(start==end)
	{
		tree[tree_node]=arr[start];
		return ;
	}
	int mid = start + (end-start)/2;
	build_tree(arr,tree,start,mid,2*tree_node);
	build_tree(arr,tree,mid+1,end,2*tree_node+1);
	tree[tree_node]=max(tree[2*tree_node],tree[2*tree_node + 1]);
	return ;
}

void update(int* tree,int* lazy,int start,int end,int tree_node,int left,int right,int value)
{
	if(start > end)
	{
		return;
	}
	if(lazy[tree_node]!=0)
	{
		tree[tree_node]+=lazy[tree_node];
		//not leaf node
		if(start!=end)
		{	
			lazy[2*tree_node]+=lazy[tree_node];
			lazy[2*tree_node+1]+=lazy[tree_node];
		}
		lazy[tree_node]=0;
		return ;
	}
	// completely inside
	if(start >= left && end <= right)
	{
		tree[tree_node]+=value;
		if(start!=end)
		{
			lazy[2*tree_node]+=value;
			lazy[2*tree_node + 1]+=value;
		}
		return ;
		
	}
	// completely outside
	if(start > right || end < left)
	{
		return ;
	}
	int mid = start + (end-start)/2;
	update(tree,lazy,start,mid,2*tree_node,left,right,value);
	update(tree,lazy,mid+1,end,2*tree_node+1,left,right,value);
	tree[tree_node]=max(tree[2*tree_node],tree[2*tree_node+1]);
	return;
}

int query_tree(int* tree,int* lazy,int start,int end,int tree_node,int left,int right)
{
	
	if(lazy[tree_node]!=0)
	{
		tree[tree_node]+=lazy[tree_node];
		//not leaf node
		if(start!=end)
		{	
			lazy[2*tree_node]+=lazy[tree_node];
			lazy[2*tree_node+1]+=lazy[tree_node];
		}
		lazy[tree_node]=0;
	}
	// completely inside
	if(start >= left && end <= right)
	{
		return tree[tree_node];
	}
	// completely outside
	if(start > right || end < left)
	{
		return INT_MIN;
	}
	// partially
	int mid = start + (end-start)/2;
	int l1 = query_tree(tree,lazy,start,mid,2*tree_node,left,right);
	int l2 = query_tree(tree,lazy,mid+1,end,2*tree_node+1,left,right);
	return max(l1,l2);
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
	int* tree = new int[4*n];
	int* lazy = new int[4*n]();
	build_tree(arr,tree,0,n-1,1);
	for(int i=0;i<4*n;i++)
	{
		cout << tree[i] << endl;
	}
	int k;
	cin >> k;
	while(k--)
	{
		char check;
		int left,right,value;
		cin >> check ;
		if(check == 'q')
		{
			cin >> left >> right;
			cout << query_tree(tree,lazy,0,n-1,1,left,right) << endl;
		}
		else
		{
			cin >> left >> right >> value;
			update(tree,lazy,0,n-1,1,left,right,value);
		}
	}
	return 0;
}