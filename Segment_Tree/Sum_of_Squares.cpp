#include<bits/stdc++.h>
using namespace std;


struct tree_node
{
	long SS=0;
	long S=0;

};

struct lazy_node
{
	int type=0;//0 do nothing,1-increament,2-change
	long value=0;
};

void build_tree(int* arr,tree_node* tree,int start,int end,int index)
{
	if(start==end)
	{
		tree[index].SS = arr[start]*arr[start];
		tree[index].S = arr[start];
		return ;
	}
	int mid = start + (end-start)/2;
	build_tree(arr,tree,start,mid,2*index);
	build_tree(arr,tree,mid+1,end,2*index+1);
	tree[index].SS = tree[2*index].SS + tree[2*index+1].SS;
	tree[index].S = tree[2*index].S + tree[2*index+1].S;
	return ;
}

void update_tree(tree_node* tree,lazy_node* lazy_tree,int start,int end,int index,int left,int right,
					int type,int value)
{

	if(lazy_tree[index].type!=0)
	{
		long temp = tree[index].S;
		if(lazy_tree[index].type==1)
		{
			long v = lazy_tree[index].value;
			tree[index].S += v*(end-start+1);
			tree[index].SS += (end-start+1)*v*v + 2*v*(temp); 
		}
		else
		{
			long v = lazy_tree[index].value;
			tree[index].S = v*(end-start+1);
			tree[index].SS = (end-start+1)*v*v;
		}
		if(start!=end)
		{
			lazy_tree[2*index].type = lazy_tree[index].type;
			lazy_tree[2*index+1].type = lazy_tree[index].type;
			lazy_tree[2*index].value = lazy_tree[index].value;
			lazy_tree[2*index+1].value = lazy_tree[index].value;
		}
		lazy_tree[index].type = 0;
		lazy_tree[index].value = 0;
	}
	// completely inside
	if(start >= left && end <= right)
	{
		long temp = tree[index].S;
		if(type==1)
		{
			tree[index].S += value*(end-start+1);
			tree[index].SS += (end-start+1)*value*value + 2*value*(temp);
			if(start!=end)
			{
				lazy_tree[2*index].type = type;
				lazy_tree[2*index+1].type = type;
				lazy_tree[2*index].value = value;
				lazy_tree[2*index+1].value = value;
			}
		}
		else if(type==2)
		{
			tree[index].S = value*(end-start+1);
			tree[index].SS = (end-start+1)*value*value;
			if(start!=end)
			{
				lazy_tree[2*index].type = type;
				lazy_tree[2*index+1].type = type;
				lazy_tree[2*index].value = value;
				lazy_tree[2*index+1].value = value;
			}
		}
		return ;
	}
	// completely outside
	if(start > right || end < left)
	{
		return ;
	}
	//partially
	int mid = start + (end-start)/2;
	update_tree(tree,lazy_tree,start,mid,2*index,left,right,type,value);
	update_tree(tree,lazy_tree,mid+1,end,2*index+1,left,right,type,value);
	tree[index].SS = tree[2*index].SS + tree[2*index+1].SS;
	tree[index].S = tree[2*index].S + tree[2*index+1].S;
	return ;
}

long query_tree(tree_node* tree,lazy_node* lazy_tree,int start,int end,int index,int left,int right)
{
	if(lazy_tree[index].type!=0)
	{
		long temp = tree[index].S;
		if(lazy_tree[index].type==1)
		{
			long v = lazy_tree[index].value;
			tree[index].S += v*(end-start+1);
			tree[index].SS += (end-start+1)*v*v + 2*v*(temp); 
		}
		else
		{
			long v = lazy_tree[index].value;
			tree[index].S = v*(end-start+1);
			tree[index].SS = (end-start+1)*v*v;
		}
		if(start!=end)
		{
			lazy_tree[2*index].type = lazy_tree[index].type;
			lazy_tree[2*index+1].type = lazy_tree[index].type;
			lazy_tree[2*index].value = lazy_tree[index].value;
			lazy_tree[2*index+1].value = lazy_tree[index].value;
		}
		lazy_tree[index].type = 0;
		lazy_tree[index].value = 0;
	}
	if(start >= left &&  end <= right)
	{
		return tree[index].SS;
	}
	if(start > right || end < left)
	{
		return 0;
	}
	int mid = start + (end - start)/2;
	long l = query_tree(tree,lazy_tree,start,mid,2*index,left,right);
	long r = query_tree(tree,lazy_tree,mid+1,end,2*index+1,left,right);
	return l+r;
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
	tree_node* tree = new tree_node[4*n];
	lazy_node* lazy_tree = new lazy_node[4*n];
	build_tree(arr,tree,0,n-1,1);
	for(int i=1;i<4*n;i++)
	{
		cout << tree[i].SS << "," << tree[i].S << endl;
	}
	long left,right,type,value;
	cin >> type  >> left >> right >> value;
	update_tree(tree,lazy_tree,0,n-1,1,left,right,type,value);
	for(int i=1;i<4*n;i++)
	{
		cout << tree[i].SS << "," << tree[i].S << endl;
	}
	cin >> left >> right;
	cout << query_tree(tree,lazy_tree,0,n-1,1,left,right) << endl;
	return 0;

}