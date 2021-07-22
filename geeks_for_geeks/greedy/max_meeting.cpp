#include<bits/stdc++.h>
using namespace std;

struct node
{
	int start;
	int end;
	int index;
};
typedef struct node node;


bool compare(node* a,node* b)
{
	return a->end < b->end;//ascending order
}
int main()
{
	int n;
	cin >> n;
	node** arr = new node*[n];
	for(int i=0;i<n;i++)
	{
		arr[i]=new node[n];
	}
	for(int i=0;i<n;i++)
	{
		int a,b;
		cin >> a >> b;
		node* temp = new node();
		temp->start = a;
		temp->end = b;
		temp->index = i+1;
		arr[i]=temp;
	}
	sort(arr,arr+n,compare);
	
	cout << arr[0]->index << " ";
	int check = arr[0]->end;
	for(int i=1;i<n;i++)
	{
		if(arr[i]->start >= check)
		{
			cout << arr[i]->index << " ";
			check = arr[i]->end;
		}
	}
	cout << endl;
	delete[] arr;
	return 0;
}