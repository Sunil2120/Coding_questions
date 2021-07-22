#include<bits/stdc++.h>
using namespace std;

struct node
{
	int sum=0;
	int max_sum=0;
	int BS=0;
	int BP=0;

};


void build_tree(int* arr,node* tree,int start,int end,int tree_node)
{
	if(start==end)
	{
		tree[tree_node].sum=arr[start];
		tree[tree_node].max_sum=arr[start];
		tree[tree_node].BS=arr[start];
		tree[tree_node].BP=arr[start];
		return ;
	}
	int mid = start + (end-start)/2;
	build_tree(arr,tree,start,mid,2*tree_node);
	build_tree(arr,tree,mid+1,end,2*tree_node+1);
	node left = tree[2*tree_node];
	node right = tree[2*tree_node + 1];
	tree[tree_node].sum = left.sum + right.sum;
	tree[tree_node].BS = max(right.sum,max(left.BS+right.sum,right.BS));
	tree[tree_node].BP = max(left.sum,max(right.BP+left.sum,left.BP));
	tree[tree_node].max_sum = max(left.max_sum,max(right.max_sum,max(left.sum+right.BP,max(right.sum+left.BS,left.BS+right.BP))));
	return ;
}


void update_tree(int* arr,node* tree,int start,int end,int tree_node,int key,int index)
{
	if(start==end)
	{
		if(start==index)
		{
			arr[index]=key;
			tree[tree_node].sum=key;
			tree[tree_node].max_sum=key;
			tree[tree_node].BS=key;
			tree[tree_node].BP=key;
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
	node right = tree[2*tree_node + 1];
	tree[tree_node].sum = left.sum + right.sum;
	tree[tree_node].BS = max(right.sum,max(left.BS+right.sum,right.BS));
	tree[tree_node].BP = max(left.sum,max(right.BP+left.sum,left.BP));
	tree[tree_node].max_sum = max(left.max_sum,max(right.max_sum,max(left.sum+right.BP,max(right.sum+left.BS,left.BS+right.BP))));
	return ;
}

node* query_tree(node* tree,int start,int end,int tree_node,int left,int right)
{
	// completely inside
	if(start >= left && end <= right)
	{
		node* temp = new node();
		temp->sum = tree[tree_node].sum;
		temp->max_sum = tree[tree_node].max_sum;
		temp->BS = tree[tree_node].BS;
		temp->BP = tree[tree_node].BP;
		return temp;
	}
	// completely outside
	if(start > right || end < left)
	{
		node* temp = new node();
		temp->sum = INT_MIN;
		temp->max_sum = INT_MIN;
		temp->BS = INT_MIN;
		temp->BP = INT_MIN;
		return temp;
	}
	//partially inside and partially outside
	int mid = start + (end-start)/2;
	node* l = query_tree(tree,start,mid,2*tree_node,left,right);
	node* r = query_tree(tree,mid+1,end,2*tree_node+1,left,right);
	node* temp = new node();
	temp->sum = l->sum + r->sum;
	temp->BS = max(r->sum,max(l->BS+r->sum,r->BS));
	temp->BP = max(l->sum,max(r->BP+l->sum,l->BP));
	temp->max_sum = max(l->max_sum,max(r->max_sum,max(l->sum+r->BP,max(r->sum+l->BS,l->BS+r->BP))));
	return temp;

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
	// for(int i=0;i<4*n;i++)
	// {
	// 	cout << tree[i].max_sum << endl;
	// }
	// 
	int k;
	cin >> k;
	while(k--)
	{
		int left,right;
		cin >> left >> right;
		node* result = query_tree(tree,0,n-1,1,left-1,right-1);
		cout << result->max_sum << endl;
		delete result;
	}
	delete[] tree;
	delete[] arr;


	return 0;
}