#include<bits/stdc++.h>
using namespace std;


void build_tree(int* A,int* B,int* tree,int start,int end,int tree_node)
{
	if(start==end)
	{
		tree[tree_node]=start;
		return ;
	}
	int mid = (start) + (end-start)/2;
	build_tree(A,B,tree,start,mid,2*tree_node);
	build_tree(A,B,tree,mid+1,end,2*tree_node+1);
	int left = tree[2*tree_node];
	int right = tree[2*tree_node+1];
	if(A[left] > A[right])
	{
		tree[tree_node]=left;
	}
	else if(A[left] < A[right])
	{
		tree[tree_node]=right;
	}
	else
	{
		if(B[left] < B[right])
		{
			tree[tree_node]=left;
		}
		else if(B[left] > B[right])
		{
			tree[tree_node]=right;
		}
		else
		{
			if(left < right)
			{
				tree[tree_node]=left;
			}
			else
			{
				tree[tree_node]=right;
			}
		}
	}
	return ;
}

int query_tree(int* A,int* B,int* tree,int start,int end,int tree_node,int left,int right)
{
	// inside
	if(start >= left && end <= right)
	{
		return tree[tree_node];
	}
	// outside
	if(start > right || end < left)
	{
		return -1;
	}
	// partial
	int mid = (start) + (end-start)/2;
	int l = query_tree(A,B,tree,start,mid,2*tree_node,left,right);
	int r = query_tree(A,B,tree,mid+1,end,2*tree_node+1,left,right);
	if(l==-1)
	{
		return r;
	}
	else if(r==-1)
	{
		return l;
	}
	if(A[l] > A[r])
	{
		return l;
	}
	else if(A[l] < A[r])
	{
		//tree[tree_node]=right;
		return r;
	}
	else
	{
		if(B[l] < B[r])
		{
			//tree[tree_node]=left;
			return l;
		}
		else if(B[l] > B[r])
		{
			//tree[tree_node]=right;
			return r;
		}
		else
		{
			if(l < r)
			{
				//tree[tree_node]=left;
				return l;
			}
			else
			{
				//tree[tree_node]=right;
				return r;
			}
		}
	}
	return 0;
}


int main()
{
	int n;
	cin >> n;
	int* A = new int[n];
	int* B = new int[n];
	for(int i=0;i<n;i++)
	{
		cin >> A[i];
	}
	for(int i=0;i<n;i++)
	{
		cin >> B[i];
	}
	int* tree = new int[4*n]();
	build_tree(A,B,tree,0,n-1,1);
	// for(int i=0;i<4*n;i++)
	// {
	// 	cout << tree[i] << endl;
	// }
	int k;
	cin >> k;
	while(k--)
	{
		int left,right;
		cin >> left >> right;
		cout << query_tree(A,B,tree,0,n-1,1,left-1,right-1)+1 << endl;
	}
	delete[] A;
	delete[] B;
	delete[] tree;
	return 0;
}