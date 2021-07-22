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
			tree[tree_node]+=update;
			arr[index]+=update;
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

void binary(int n,vector<int>& ones)
{
	int i=0;
	while(n!=0)
	{
		int temp = n%2;
		if(temp==1)
		{
			ones.push_back(i);
		}
		n = n/2;
		i+=1;
	}
	return ;
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
	int q;
	cin >> q;
	vector<int> ones;
	binary(q,ones);
	int start = 0;
	for(int i=0;i<ones.size();i++)
	{
		int num=pow(2,ones[i]);
		int temp = query_sum(tree,0,n-1,1,start,start+num-1);
		cout << temp << " ";
		start=start+ones[i];
	}
	cout << endl;
	int o;
	cin >> o;
	for(int i=0;i<o;i++)
	{
		int f,s;
		cin >> f >> s;
		update_tree(arr,tree,f-1,0,n-1,1,s);
		//cout << arr[f-1] << endl;
		int Qu;
		cin >> Qu;
		vector<int> ani;
		binary(Qu,ani);
		start = 0;
		for(int i=0;i<ani.size();i++)
		{
			int num=pow(2,ani[i]);
			//cout << "nums is " << num << endl;
			int temp = query_sum(tree,0,n-1,1,start,start+num-1);
			cout << temp << " ";
			start=start+ani[i];
		}
		cout << endl;
	}
	

	
	return 0;
}