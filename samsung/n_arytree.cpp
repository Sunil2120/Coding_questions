#include<bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	struct node* ptr1=NULL;
	struct node* ptr2=NULL;
	struct node* ptr3=NULL;
};
typedef struct node Node;

Node* newnode(int key)
{
	Node* temp = new Node();
	temp->data = key;
	return temp;
}

pair<int,int> solve(Node* root)
{
	if(root==NULL)
	{
		return make_pair(0,0);
	}
	pair<int,int> ptr1 = solve(root->ptr1);
	pair<int,int> ptr2 = solve(root->ptr2);
	pair<int,int> ptr3 = solve(root->ptr3);
	int first = max(ptr1.first,max(ptr2.first,ptr3.first))+1;
	int second = 0;
	vector<int> arr;
	arr.push_back(ptr1.first);
	arr.push_back(ptr2.first);
	arr.push_back(ptr3.first);
	int max_first,max_second;
	int max_value = INT_MIN;
	for(int i=0;i<3;i++)
	{
		
		for(int j=i+1;j<3;j++)
		{
			if(arr[i]+arr[j] > max_value)
			{
				max_value = arr[i]+arr[j];
				max_first = arr[i];
				max_second = arr[j];
			}
		}
	}
	second = max(ptr1.second,max(ptr2.second,ptr3.second));
	second = max(second,max_value+1);
	return make_pair(first,second);
}

int main()
{

	return 0;
}