#include<bits/stdc++.h>
using namespace std;


void  update_tree(long* tree,long* lazy,int start,int end,int tree_node,int left,int right,int value)
{

	if(lazy[tree_node]!=0)
	{
		tree[tree_node]+=(lazy[tree_node])*(end-start+1);
		if(start!=end)
		{
			lazy[2*tree_node]+=lazy[tree_node];
			lazy[2*tree_node+1]+=lazy[tree_node];
		}
		lazy[tree_node]=0;
	}

	// inside
	if(start >= left && end <= right)
	{
		tree[tree_node]+=(value)*(end-start+1);
		if(start!=end)
		{
			lazy[2*tree_node]+=value;
			lazy[2*tree_node+1]+=value;
		}
		return ;
	}
	// outside
	if(start > right || end < left)
	{
		return ;
	}
	// partial
	int mid = (start) + (end-start)/2;
	update_tree(tree,lazy,start,mid,2*tree_node,left,right,value);
	update_tree(tree,lazy,mid+1,end,2*tree_node+1,left,right,value);
	tree[tree_node]=tree[2*tree_node]+tree[2*tree_node+1];
	return ;
}

long query_tree(long* tree,long* lazy,int start,int end,int tree_node,int left,int right)
{
	if(lazy[tree_node]!=0)
	{
		tree[tree_node]+=(lazy[tree_node])*(end-start+1);
		if(start!=end)
		{
			lazy[2*tree_node]+=lazy[tree_node];
			lazy[2*tree_node+1]+=lazy[tree_node];
		}
		lazy[tree_node]=0;
	}

	// inside
	if(start >= left && end <= right)
	{
		return tree[tree_node];
	}
	// outside
	if(start > right || end < left)
	{
		return 0;
	}

	// partial
	int mid = start + (end-start)/2;
	return query_tree(tree,lazy,start,mid,2*tree_node,left,right)+query_tree(tree,lazy,mid+1,end,2*tree_node+1,left,right);

}


int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n,k;
		cin >> n >> k;
		// int* arr = new int[n]();
		long* tree = new long[4*n]();
		// for(int i=0;i<n;i++)
		// {
		// 	cin >> arr[i];
		// }
		long* lazy = new long[4*n]();
		while(k--)
		{

			int option,left,right,value;
			cin >> option;
			if(option==0)
			{
				cin >> left >> right >> value;

				update_tree(tree,lazy,0,n-1,1,left-1,right-1,value);

			}
			else
			{
				cin >> left >> right;
				cout << query_tree(tree,lazy,0,n-1,1,left-1,right-1) << endl;
			}
		}
		delete[] tree;
		delete[] lazy;
		
	}
	return 0;
	
}