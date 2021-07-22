// Following are the steps to solve the problem:
// 1.Push the first half elements of queue to stack.
// 2.Enqueue back the stack elements.
// 3.Dequeue the first half elements of the queue and enqueue them back.
// 4.Again push the first half elements into the stack.
// 5.Interleave the elements of queue and stack.


// My steps
// 1. push first half elements of queue to stack
// 2. reverse the stack
// 3.interleave the elements of queue and stack.


#include<bits/stdc++.h>
using namespace std;

void display(queue<int>& Q)
{
	for(int i=0;i<Q.size();i++)
	{
		int value = Q.front();
		Q.pop();
		Q.push(value);
		cout << value << " ";
	}
	cout << endl;
	return ;
}

void insert_bottom(stack<int>& s,int x)
{
	if(s.size()==0)
	{
		s.push(x);
		return ;
	}
	int a = s.top();
	s.pop();
	insert_bottom(s,x);
	s.push(a);
	return ;
}

void reverse(stack<int>& s)
{
	if(s.size() == 0)
	{
		return ;
	}
	int a = s.top();
	s.pop();
	reverse(s);
	insert_bottom(s,a);
	return ;
}

void display_stack(stack<int>& s)
{
	if(s.empty())
	{
		cout << endl;
		return ;
	}
	cout << s.top() << " ";
	int a = s.top();
	s.pop();
	display_stack(s);
	s.push(a);
	return ;
}
void solve(queue<int>& Q)
{
	stack<int> s;
	if((Q.size()%2)!=0)//odd we can't do anything
	{
		return ;
	}
	// put first half into stack
	int n = Q.size();
	for(int i=1;i<=(n/2);i++)
	{
		s.push(Q.front());
		Q.pop();
	}
	display_stack(s);
	//reverse stack
	reverse(s);
	display_stack(s);
	//interleaving
	while(!s.empty())
	{
		Q.push(s.top());
		s.pop();
		Q.push(Q.front());
		Q.pop();
	}
	return ;

}


// void solve(queue<int>& Q)
// {
// 	stack<int> s;
// 	if((Q.size()%2)!=0)//odd we can't do anything
// 	{
// 		return ;
// 	}
// 	// step1
// 	for(int i=0;i<(Q.size()/2);i++)
// 	{
// 		s.push(Q.front());
// 		Q.pop();
// 	}
// 	//step 2
// 	while(s.size() > 0)
// 	{
// 		Q.push(s.top());
// 		s.pop();
// 	}
// 	//step 3
// 	for(int i=0;i<(Q.size()/2);i++)
// 	{
// 		int temp = Q.front();
// 		Q.pop();
// 		Q.push(temp);
// 	}
// 	//step 4
// 	for(int i=0;i<(Q.size()/2);i++)
// 	{
// 		s.push(Q.front());
// 		Q.pop();
// 	}
// 	//step 5
// 	//interleave
// 	while(!s.empty())
// 	{
// 		Q.push(s.top());
// 		s.pop();
// 		Q.push(Q.front());
// 		Q.pop();
// 	}
// 	return ;
// }

int main()
{
	int n;
	cin >> n;
	queue<int> Q;
	for(int i=0;i<n;i++)
	{
		int val;
		cin >> val;
		Q.push(val);
	}
	display(Q);
	solve(Q);
	display(Q);
	return 0;
}
