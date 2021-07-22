#include<bits/stdc++.h>
using namespace std;


typedef long long ll;
struct node
{
	ll max_=0;
	ll smax_ = 0;
};
typedef struct node Node;


void build(Node* tree,vector<ll>& arr,int start,int end,int tree_index)
{
	if(start==end)
	{
		Node temp;
		temp.max_ = arr[start];
		tree[tree_index]=temp;
		return ;
	}
	int mid = start + (end-start)/2;
	build(tree,arr,start,mid,2*tree_index);
	build(tree,arr,mid+1,end,2*tree_index+1);
	Node left = tree[2*tree_index];
	Node right = tree[2*tree_index + 1];
	tree[tree_index].max_ = max(left.max_,right.max_);
	if(tree[tree_index].max_ == left.max_)
	{
		tree[tree_index].smax_ = max(left.smax_,right.max_);
	}
	else
	{
		tree[tree_index].smax_ = max(left.max_,right.smax_);
	}
	return ;
}

Node query(Node* tree,int start,int end,int tree_index,int r1,int r2)
{
	//completely inside
	if(start >= r1 && end <= r2)
	{
		return tree[tree_index];
	}
	//completly outside
	if(end < r1 || start > r2)
	{
		Node temp;
		return temp;
	}
	int mid = start + (end-start)/2;
	Node left = query(tree,start,mid,2*tree_index,r1,r2);
	Node right = query(tree,mid+1,end,2*tree_index +1,r1,r2);
	Node temp;
	temp.max_ = max(left.max_,right.max_);
	if(temp.max_ == left.max_)
	{
		temp.smax_ = max(left.smax_,right.max_);
	}
	else
	{
		temp.smax_ = max(left.max_,right.smax_);
	}
	return temp;
}

void update(Node* tree,vector<ll>& arr,int start,int end,int tree_index,int index,int value)
{
	if(start==end)
	{
		if(start==index)
		{
			arr[index]=value;
			tree[tree_index].max_ = value;
			tree[tree_index].smax_ = INT_MIN;
		}
		return ;
	}
	int mid = start + (end-start)/2;
	if(index <= mid)
		update(tree,arr,start,mid,2*tree_index,index,value);
	else
		update(tree,arr,mid+1,end,2*tree_index+1,index,value);
	Node left = tree[2*tree_index];
	Node right = tree[2*tree_index + 1];
	tree[tree_index].max_ = max(left.max_,right.max_);
	if(tree[tree_index].max_ == left.max_)
	{
		tree[tree_index].smax_ = max(left.smax_,right.max_);
	}
	else
	{
		tree[tree_index].smax_ = max(left.max_,right.smax_);
	}
	return ;

}


int main()
{
	int n;
	cin >> n;
	vector<ll> arr(n);
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
	}
	Node* tree = new Node[4*n];
	build(tree,arr,0,n-1,1);
	int m;
	cin >> m;

	while(m--)
	{
		int l,r;
		char k;
		cin >> k;
		cin  >> l >> r;
		if(k=='U')
		{
			update(tree,arr,0,n-1,1,l-1,r);
		}
		else
		{
			Node res = query(tree,0,n-1,1,l-1,r-1);
			cout << res.max_ + res.smax_ << endl;
		}
	}
	return 0;
}