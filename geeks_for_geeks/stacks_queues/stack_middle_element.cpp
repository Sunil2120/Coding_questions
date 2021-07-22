// Find middle element 
// push element to mystack
// pop element from the mystack
// delete middle element

// finding middle element , push and pop operations take O(1) time
// but deleting middle element in arrays is not possible
// if we use singly linked list deleting middle element takes O(N)
// so it's better to use doubly linked list where deleting middle takes O(1)

#include<bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	struct node* prev;
	struct node* next;
};
typedef struct node Node;

struct mystack
{
	int size;
	int capacity;
	Node* mid;
	Node* top;
};
typedef struct mystack Mystack;


Node* create_node(int item)
{
	Node* temp = new Node();
	temp->data = item;
	temp->prev=temp->next=NULL;
	return temp;
}

Mystack* create_mystack(int capacity)
{
	Mystack* mystack = new Mystack();
	mystack->capacity = capacity;
	mystack->size = 0;
	mystack->mid = NULL;
	mystack->top = NULL;
	return mystack;
}

bool isFull(Mystack* mystack)
{
	if(mystack->size == mystack->capacity)
	{
		return true;
	}
	return false;
}

bool isEmpty(Mystack* mystack)
{
	if(mystack->size == 0)
	{
		return true;
	}
	return false;
}

void push(Mystack* mystack,int item)
{
	if(isFull(mystack))
	{
		return ;
	}
	Node* temp = create_node(item);
	Node* top = mystack->top;
	if(top==NULL)
	{
		top=temp;
		mystack->mid = top;
		mystack->top = top;
		mystack->size += 1;
		return ;
	}
	top->next = temp;
	temp->prev = top;
	top = top->next;
	mystack->size += 1;
	if((mystack->size%2)==0 && mystack->mid!=NULL)// if mystack size is even
	{
		mystack->mid = mystack->mid->next;
	}
	mystack->top = top;
	return ;
}

int pop(Mystack* mystack)
{
	if(isEmpty(mystack))
	{
		return -1;
	}
	Node* top = mystack->top;
	int output = top->data;
	if(mystack->size==1)
	{
		mystack->mid = NULL;
	}
	Node* prev = top->prev;
	prev->next = NULL;
	top->prev = NULL;
	top = prev;
	mystack->size -=1;
	if((mystack->size%2)!=0 && mystack->mid!=NULL)// if current mystack size is odd
	{
		mystack->mid = mystack->mid->prev;
	}
	mystack->top = top;
	return output;
}

int get_middle(Mystack* mystack)
{
	if(isEmpty(mystack))
	{
		return -1;
	}
	return mystack->mid->data;
}

void delete_mid(Mystack* mystack)
{
	if(isEmpty(mystack))
	{
		return ;
	}
	Node* cur = mystack->mid;
	cur->prev->next = cur->next->prev;
	mystack->size-=1;
	if((mystack->size%2)==0)//even
	{
		mystack->mid = cur->next;
		delete cur;
	}
	else
	{
		mystack->mid = cur->prev;
		delete cur;
	}
	return ;

}

int main()
{
	Mystack* mystack = create_mystack(100);
	int n;
	cin >> n;
	while(n--)
	{
		int value;
		string input;
		cin >> input;
		if(input=="push")
		{
			cin >> value;
			push(mystack,value);
		}	
		else if(input=="pop")
		{
			cout << pop(mystack) << endl;
		}
		else if(input=="get_middle")
		{
			cout << get_middle(mystack) << endl;
		}
		else if(input=="delete_mid")
		{
			delete_mid(mystack);
		}
	}
	return 0;
}



