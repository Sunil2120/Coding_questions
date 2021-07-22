#include<bits/stdc++.h>
using namespace std;
// this is done using additional stack
// sort stack such that the greater elements remain at top of the stack

void print_stack(stack<int>& original)
{
	vector<int> temp2;
	while(original.size() > 0)
	{
		cout << original.top() << " ";
		temp2.push_back(original.top());
		original.pop();
	}
	cout << endl;
	for(int i=0;i<temp2.size();i++)
	{
		original.push(temp2[i]);
	}
	return ;
}

// if top of the stack is smaller ----- we will insert into the stack
// if top of the stack is larger ------ we will remove the top and insert key to proper position 
// and then push the poped element


void insert_at_right_position(stack<int>& original,int temp)
{
	if(original.size()==0 || original.top()>= temp)
	{
		original.push(temp);
		return ;
	}
	int a = original.top();
	original.pop();
	insert_at_right_position(original,temp);
	original.push(a);
	return ;
}

// remove
// sort the stack 
// insert at right position
void sort(stack<int>& original)
{
	if(original.size()==0)
	{
		return ;
	}
	int a = original.top();
	original.pop();
	sort(original);
	insert_at_right_position(original,a);
	return ;
}

int main()
{
	stack<int> original;
	stack<int> temp;
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		int val;
		cin >> val;
		original.push(val);
	}
	print_stack(original);
	sort(original);
	print_stack(original);
	return 0;
}