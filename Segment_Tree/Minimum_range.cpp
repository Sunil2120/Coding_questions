#include<bits/stdc++.h>
using namespace std;

void build_tree(int* arr,int* tree,int start,int end,int index)
{
	if(start == end)
	{
		tree[index]=arr[start];
		return ;
	}
	int mid = start + (end-start)/2;
	build_tree(arr,tree,start,mid,2*index);
	build_tree(arr,tree,mid+1,end,2*index + 1);
	tree[index]=min(tree[2*index],tree[2*index+1]);
}


void update_tree(int* arr,int* tree,int start,int end,int tree_node,int key,int index)
{
	if(start==end)
	{
		if(start==index)
		{
			tree[tree_node]=key;
			arr[index]=key;
		}
		return ;
	}
	int mid = start + (end-start)/2;
	if(index > mid)
	{
		update_tree(arr,tree,mid+1,end,2*tree_node+1,key,index);
	}
	else
	{
		update_tree(arr,tree,start,mid,2*tree_node,key,index);
	}
	tree[tree_node] = min(tree[2*tree_node],tree[2*tree_node+1]);
}


int query(int* tree,int start,int end,int tree_node,int left,int right)
{
	// completely inside
	if(start >=left && end <= right)
	{
		return tree[tree_node];
	}
	// completly outside
	if(start > right || end < left)
	{
		return INT_MAX;
	}

	// partially inside and partially outside
	int mid = start + (end-start)/2;
	return min(query(tree,start,mid,2*tree_node,left,right),query(tree,mid+1,end,2*tree_node+1,left,right));


}

int main()
{
	int n,k;
	cin >> n >> k;
	int* arr = new int[n];
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
	}
	int* tree = new int[4*n]();
	build_tree(arr,tree,0,n-1,1);
	// for(int i=0;i<4*n;i++)
	// {
	// 	cout << tree[i] << " ";
	// }
	// cout << endl;
	while(k--)
	{
		char check;
		int left,right;
		cin >> check >> left >> right;
		if(check=='q')
		{
			cout << query(tree,0,n-1,1,left-1,right-1);
			continue;
		}
		else
		{
			update_tree(arr,tree,0,n-1,1,right,left-1);
			// for(int i=0;i<4*n;i++)
			// {
			// 	cout << tree[i] << " ";
			// }
			// cout << endl;

		}

	}
	return 0;
}