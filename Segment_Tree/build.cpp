#include<bits/stdc++.h>
using namespace std;


void build_tree(int* arr,int* tree,int start,int end,int tree_node)
{
	// base case
	if(start == end)
	{
		tree[tree_node] = arr[start];
		return ;
	}
	int mid = start + (end-start)/2;
	// left subtree
	build_tree(arr,tree,start,mid,2*tree_node);
	// right subtree
	build_tree(arr,tree,mid+1,end,2*tree_node + 1);

	tree[tree_node] = tree[2*tree_node] + tree[2*tree_node + 1];
}


void update_tree(int* arr,int* tree,int index,int start,int end,int tree_node,int update)
{
	if(start==end)
	{
		if(start == index)
		{
			tree[tree_node]=update;
			arr[index]=update;
		}
		
		return ;
	}
	int mid = start + (end-start)/2;
	if(index > mid)
	{
		update_tree(arr,tree,index,mid+1,end,2*tree_node+1,update);
	}
	else
	{
		update_tree(arr,tree,index,start,mid,2*tree_node,update);
	}
	
	//update_tree(tree,index,mid+1,end,2*tree_node+1,update);

	tree[tree_node] = tree[2*tree_node] + tree[2*tree_node + 1];

}


int query_sum(int* tree,int start,int end,int tree_node,int r1,int r2)
{
	// completely inside
	if(start >= r1 && end <= r2)
	{
		return tree[tree_node];
	}
	// completely outside
	if((start < r1 && end < r1) || (start > r2 && end > r2))
	{
		return 0;
	}

	int mid = start + (end-start)/2;
	return query_sum(tree,start,mid,2*tree_node,r1,r2) + query_sum(tree,mid+1,end,2*tree_node + 1,r1,r2);
}



int main()
{
	int n;
	cin >> n;
	int* arr = new int[n];
	int* tree = new int[2*n];// tree size is 2n
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
	}
	build_tree(arr,tree,0,n-1,1);
	for(int i=1;i<2*n;i++)
	{
		cout << tree[i] << endl;
	}
	cout << query_sum(tree,0,n-1,1,1,4) << endl;
	

	return 0;
}