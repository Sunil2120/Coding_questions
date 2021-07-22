#include<bits/stdc++.h>
using namespace std;


int gcd(int a,int b)
{
	if(b > a)
	{
		return gcd(b,a);
	}
	if(b==0)
	{
		return a;
	}
	return gcd(b,a%b);
}

void build_tree(int* arr,int* tree,int start,int end,int tree_index)
{
	if(start==end)
	{
		tree[tree_index]=arr[start];
		return ;
	}
	int mid = start + (end-start)/2;
	build_tree(arr,tree,start,mid,2*tree_index);
	build_tree(arr,tree,mid+1,end,2*tree_index+1);
	tree[tree_index] = gcd(tree[2*tree_index],tree[2*tree_index+1]);
	return ;
}

int query(int* tree,int start,int end,int tree_index,int left,int right)
{
	// completely inside
	if(start >= left && end <= right)
	{
		return tree[tree_index];
	}
	// completely outside
	if(start > right || end < left)
	{
		return 0;
	}
	// partial
	int mid = start + (end-start)/2;
	int l = query(tree,start,mid,2*tree_index,left,right);
	int r = query(tree,mid+1,end,2*tree_index+1,left,right);
	return gcd(l,r);
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
	build_tree(arr,tree,0,n-1,1);
	int q;
	cin >> q;
	for(int i=0;i<q;i++)
	{
		int left,right;
		cin >> left >> right;
		cout << query(tree,0,n-1,1,left,right);
	}
	delete[] tree;
	delete[] arr;
	return 0;
}