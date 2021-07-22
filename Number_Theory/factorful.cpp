#include<bits/stdc++.h>
using namespace std;
#define MAX 1000000



struct node
{
	map<int,int> hash;

};
typedef struct node node;


void  getarr(int* arr)
{
	arr[1]=0;
	for(int i=2;i<=MAX;i++)
	{
		if(arr[i]==0)
		{
			arr[i]+=1;
			for(int j=2;j*i<=MAX;j=j+1)
			{
				arr[j*i]+=1;
			}
		}
	}
	return ;
}

void build_tree(node* tree,int* arr,int start,int end,int tree_index)
{
	//base case
	if(start==end)
	{
		int value = arr[start];
		tree[tree_index].hash[value]+=1;
		return ;
	}
	int mid = start + (end-start)/2;
	build_tree(tree,arr,start,mid,2*tree_index);
	build_tree(tree,arr,mid+1,end,2*tree_index+1);
	map<int,int> m1 = tree[2*tree_index].hash;
	map<int,int> m2 = tree[2*tree_index+1].hash;
	map<int,int> :: iterator it = m2.begin();
	for(it=m2.begin();it!=m2.end();it++)
	{
		int f = it->first;
		int s = it->second;
		m1[f]+=s;
	}
	tree[tree_index].hash = m1;
	return;
}

node* query(node* tree,int start,int end,int left,int right,int tree_index)
{
	// completely inside
	if(start>= left && end<= right)
	{
		node* temp = new node();
		temp->hash = tree[tree_index].hash;
		return temp;
	}
	// completely outside
	if(start > right || end < left)
	{
		node* temp = new node();
		return temp;
	}
	// partial
	int mid = start + (end-start)/2;
	node* l = query(tree,start,mid,left,right,2*tree_index);
	node* r = query(tree,mid+1,end,left,right,2*tree_index+1);
	node* temp = new node();
	map<int,int> m1 = l->hash;
	map<int,int> m2 = r->hash;
	map<int,int> :: iterator it = m2.begin();
	for(it=m2.begin();it!=m2.end();it++)
	{
		int f = it->first;
		int s = it->second;
		m1[f]+=s;
	}
	temp->hash = m1;
	return temp;
}

int main()
{
	int t;
	cin >> t;
	int* arr = new int[MAX+1]();
	getarr(arr);
	node* tree = new node[(4*MAX)+4];
	build_tree(tree,arr,0,MAX,1);

	while(t--)
	{
		int start,end,value;
		cin >> start >> end >> value;
		node* result = query(tree,0,MAX,start,end,1);
		cout << result->hash[value] << endl;
	}
	delete[] arr;
	delete[] tree;
	return 0;
}