#include<bits/stdc++.h>
using namespace std;


struct node
{
	int data;
	struct node* prev;
	struct node* next;
};
typedef struct node Node;

Node* create_node(int item)
{
	Node* temp = new Node();
	temp->data = item;
	temp->prev = NULL;
	temp->next = NULL;
	return temp;
}

class Queue
{
	private:
		Node* head;
		Node* tail;
	public:

		Queue()
		{
			head=tail=NULL;
		}
		bool isEmpty()
		{
			if(head==NULL)
			{
				return true;
			}
			return false;
		}
		int size()
		{
			Node* cur = head;
			int count = 0;
			while(cur!=NULL)
			{
				count+=1;
				cur = cur->next;
			}
			return count;
		}

		void insert_front(int item)
		{
			Node* temp = create_node(item);
			if(head==NULL)
			{
				head=temp;
				tail = temp;
				return ;
			}
			temp->next = head;
			head->prev = temp;
			head=head->prev;
			return ;
		}
		void EnQueue(int item)
		{
			Node* temp = create_node(item);
			if(head==NULL)
			{
				head=temp;
				tail = temp;
				return ;
			}
			tail->next = temp;
			temp->prev = tail;
			tail = tail->next;
			return ;
		}
		int DeQueue()
		{
			if(head==NULL)
			{
				return -1;
			}
			if(head==tail)
			{
				int output = head->data;
				head=NULL;
				tail=NULL;
				return output;
			}
			Node* temp = head;
			head=head->next;
			head->prev = NULL;
			temp->next = NULL;
			return temp->data;
		}
		int remove_end()
		{
			if(head==NULL)
			{
				return -1;
			}
			if(head==tail)
			{
				int output = head->data;
				head=NULL;
				tail=NULL;
				return output;
			}
			Node* temp = tail;
			tail = tail->prev;
			tail->next = NULL;
			temp->prev = NULL;
			return temp->data;
		}
		void display()
		{
			Node* cur = head;
			while(cur!=NULL)
			{
				cout << cur->data << " ";
				cur=cur->next;
			}
			cout << endl;
			return;

		}
};


class Stack : public Queue
{
	public:
		void get_size()
		{
			size();
		}
		void push(int item)
		{
			insert_front(item);
		}
		int pop()
		{
			return DeQueue();
		}
		void Display()
		{
			display();
		}
};

int main()
{
	Stack s;
	int n;
	cin >> n;
	while(n--)
	{
		string input;
		cin >> input;
		int item;
		if(input=="push")
		{
			cin >> item;
			s.push(item);
		}
		else if(input=="pop")
		{
			cout << s.pop() << endl;
		}
		else
		{
			s.Display();
		}

	}

	return 0;
}