#include<bits/stdc++.h>
using namespace std;


class circular_queue
{
	public:
		int rear;
		int front;
		int size;
		int capacity;
		int* arr;
		circular_queue(int n)
		{
			capacity = n;
			size = 0;
			rear = front = -1;
			arr = new int[n];
		}
		bool isFull()
		{
			if(front==0 && rear == capacity-1 || size==capacity)
			{
				return true;
			}
			
			return false;
		}
		void Enqueue(int item)
		{
			if(isFull())
			{
				cout << "full" << endl;
				return ;
			}
			size+=1;
			if(front==-1)
			{
				front = rear = 0;
				arr[rear]=item;
				return ;
			}
			if(rear==capacity-1 && front!=0)
			{
				rear = 0;
				arr[rear]=item;
				return ;
			}
			rear+=1;
			arr[rear]=item;
			return ;
		}

		int Dequeue()
		{
			if(front==-1)
			{
				return -1;
			}
			size-=1;
			int output = arr[front];
			if(front==rear)
			{
				front=rear=-1;
				// only one node
			}
			else if(front==capacity-1)
			{
				front = 0;
			}
			else
			{
				front+=1;
			}
			return output;
		}

		void display()
		{
			if(front==-1)
			{
				cout << "empty" << endl;
				return ;
			}
			if(rear >= front)
			{
				for(int i=front;i<=rear;i++)
				{
					cout << arr[i] << " ";
				}
				cout << endl;
				return ;
			}
			else
			{
				for(int i=front;i<capacity;i++)
				{
					cout << arr[i] << " ";
				}
				for(int i=0;i<=rear;i++)
				{
					cout << arr[i] << " ";
				}
				cout << endl;
				return ;
			}
			return ;
		}
};


int main()
{
	circular_queue Q(5);
	Q.Enqueue(14);
	Q.Enqueue(22);
	Q.Enqueue(13);
	Q.Enqueue(-6);
	Q.display();
	cout << "deleted item is " << Q.Dequeue() << endl;
	cout << "deleted item is " << Q.Dequeue() << endl;
	Q.display();
	Q.Enqueue(9);
	Q.Enqueue(20);
	Q.Enqueue(5);
	Q.display();
	Q.Enqueue(20);
	Q.display();
	return 0;
}
