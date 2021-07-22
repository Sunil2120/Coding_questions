#include<bits/stdc++.h>
using namespace std;

struct node
{
	int maximum=0;
	int smaximum=0;
};

void build_tree(int* arr,node* tree,int start,int end,int tree_node)
{
	if(start==end)
	{
		tree[tree_node].maximum=arr[start];
		tree[tree_node].smaximum=INT_MIN;
		return ;
	}
	int mid = start + (end-start)/2;
	build_tree(arr,tree,start,mid,2*tree_node);
	build_tree(arr,tree,mid+1,end,2*tree_node+1);
	node left = tree[2*tree_node];
	node right = tree[2*tree_node+1];
	tree[tree_node].maximum=max(left.maximum,right.maximum);
	tree[tree_node].smaximum = min(max(left.maximum,right.smaximum),max(right.maximum,left.smaximum));
}

void update_tree(int* arr,node* tree,int start,int end,int tree_node,int key,int index)
{
	if(start==end)
	{
		if(start==index)
		{
			tree[tree_node].maximum = key;
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
	node left = tree[2*tree_node];
	node right = tree[2*tree_node+1];
	tree[tree_node].maximum=max(left.maximum,right.maximum);
	tree[tree_node].smaximum = min(max(left.maximum,right.smaximum),max(right.maximum,left.smaximum));
}


pair<int,int> query(node* tree,int start,int end,int tree_node,int left,int right)
{
	// completely inside
	if(start >= left && end <= right)
	{
		return make_pair(tree[tree_node].maximum,tree[tree_node].smaximum);
	}
	// completely outside
	if(start > right || end < left)
	{
		return make_pair(INT_MIN,INT_MIN);

	}
	// partially outside and inside
	int mid = start + (end-start)/2;
	pair<int,int> left_ = query(tree,start,mid,2*tree_node,left,right);
	pair<int,int> right_ = query(tree,mid+1,end,2*tree_node+1,left,right);
	pair<int,int> total;
	total.first = max(left_.first,right_.first);
	total.second =min(max(left_.first,right_.second),max(right_.first,left_.second));
	return total;


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
	for(int i=0;i<4*n;i++)
	{
		cout << tree[i].maximum << "," << tree[i].smaximum << endl;
	}
	int k;
	cin >> k;
	while(k--)
	{
		char check;
		int left,right;
		cin >> check >> left >> right;
		if(check=='Q')
		{
			pair<int,int> result = query(tree,0,n-1,1,left-1,right-1);
			cout << result.first + result.second << endl;
		}
		else
		{
			update_tree(arr,tree,0,n-1,1,right,left-1);
		}
	}
	return 0;
}