#include<bits/stdc++.h>
using namespace std;


//Time complexity
// Enque(insertion)           O(1)
// Deque(deletion)            O(1)
// Front(Get front)           O(1)
// Rear(Get Rear)             O(1)
struct Queue
{
	int capacity;
	int size;
	int rear;
	int front;
	int* arr;
};

typedef struct Queue Queue;


Queue* create(int capacity)
{
	Queue* queue = new Queue();
	queue->capacity = capacity;
	queue->size = 0;
	queue->front = 0;
	// this is important
	queue->rear = queue->capacity - 1;
	queue->arr = new int[(queue->capacity)*sizeof(int)];
	return queue;
}

bool isFull(Queue* queue)
{
	if(queue->size == queue->capacity)
	{
		return true;
	}
	return false;
}

bool isEmpty(Queue* queue)
{
	if(queue->size == 0)
	{
		return true;
	}
	return false;
}

void enqueue(Queue* queue,int item)
{
	if(isFull(queue))
	{
		return ;
	}
	queue->rear = (queue->rear + 1)%queue->capacity;
	queue->arr[queue->rear]=item;
	queue->size+=1;
	return ;
}

int dequeue(Queue* queue)
{
	if(isEmpty(queue))
	{
		return -1;
	}
	int output = queue->arr[queue->front];
	queue->front = (queue->front + 1)%queue->capacity;
	queue->size -=1;
	return output;
}

int get_front(Queue* queue)
{
	if(isEmpty(queue))
	{
		return -1;
	}
	return queue->arr[queue->front];
}

int get_rear(Queue* queue)
{
	if(isEmpty(queue))
	{
		return -1;
	}
	return queue->arr[queue->rear];
}

int main()
{

	Queue* queue = create(1000); 
  
    enqueue(queue, 10); 
    enqueue(queue, 20); 
    enqueue(queue, 30); 
    enqueue(queue, 40); 
  
    cout << dequeue(queue) 
         << " dequeued from queue\n"; 
  
    cout << "Front item is "
         << get_front(queue) << endl; 
    cout << "Rear item is "
         << get_rear(queue) << endl; 
  
    return 0; 

}