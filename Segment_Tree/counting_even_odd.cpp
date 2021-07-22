#include<bits/stdc++.h>
using namespace std;


struct node
{
	int even=0;
	int odd = 0;

};


void build_tree(int* arr,node* tree,int start,int end,int tree_node)
{
	if(start==end)
	{
		if(arr[start]%2==0)
		{
			tree[tree_node].even = 1;
		}
		else
		{
			tree[tree_node].odd = 1;
		}
		return ;
	}
	int mid = start + (end-start)/2;
	build_tree(arr,tree,start,mid,2*tree_node);
	build_tree(arr,tree,mid+1,end,2*tree_node+1);
	tree[tree_node].even = tree[2*tree_node].even + tree[2*tree_node+1].even;
	tree[tree_node].odd = tree[2*tree_node].odd + tree[2*tree_node+1].odd;
	return ;
}

void update_tree(int* arr,node* tree,int start,int end,int tree_node,int key,int index)
{
	if(start==end)
	{
		if(start==index)
		{
			arr[start]=key;
			if(key%2==0)
			{
				tree[tree_node].even = 1;
				tree[tree_node].odd = 0;
			}
			else
			{
				tree[tree_node].odd = 1;
				tree[tree_node].even = 0;
			}
		}
		return ;
	}
	int mid = (start) + (end-start)/2;
	if(index > mid)
	{
		update_tree(arr,tree,mid+1,end,2*tree_node+1,key,index);
	}
	else
	{
		update_tree(arr,tree,start,mid,2*tree_node,key,index);
	}
	tree[tree_node].even = tree[2*tree_node].even + tree[2*tree_node+1].even;
	tree[tree_node].odd = tree[2*tree_node].odd + tree[2*tree_node+1].odd;
	return ;

}

pair<int,int> query_tree(node* tree,int start,int end,int tree_node,int left,int right)
{
	// inside
	if(start >= left && end <= right)
	{
		return make_pair(tree[tree_node].even,tree[tree_node].odd);
	}
	// outside
	if(start > right || end < left)
	{
		return make_pair(0,0);
	}
	// partial
	int mid = (start) + (end-start)/2;
	pair<int,int> l = query_tree(tree,start,mid,2*tree_node,left,right);
	pair<int,int> r = query_tree(tree,mid+1,end,2*tree_node+1,left,right);
	return make_pair(l.first+r.first,l.second+r.second);
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
	node* tree = new node[4*n];
	build_tree(arr,tree,0,n-1,1);
	int t;
	cin >> t;
	while(t--)
	{
		int k;
		cin >> k;
		int left,right,value;
		if(k==0)
		{
			cin >> left >> right;
			update_tree(arr,tree,0,n-1,1,right,left-1);
		}
		else if(k==1)
		{
			cin >> left >> right;
			pair<int,int> result = query_tree(tree,0,n-1,1,left-1,right-1);
			cout << result.first << endl;
		}
		else
		{
			cin >> left >> right;
			pair<int,int> result = query_tree(tree,0,n-1,1,left-1,right-1);
			cout << result.second << endl;
		}

	}
	delete[] tree;
	delete[] arr;
	return 0;
}