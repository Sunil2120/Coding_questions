#include<bits/stdc++.h>
using namespace std;


class k_queue
{

	public:
		int n;
		int* arr;
		int k;
		int* front;
		int* rear;
		int* next;
		int free;
		k_queue(int n,int k)
		{
			n = n;
			k=k;
			free = 0;
			arr = new int[n]();
			front = new int[k];
			rear = new int[k];
			next = new int[n];
			for(int i=0;i<k;i++)
			{
				front[i]=-1;
				rear[i]=-1;
			}
			for(int i=0;i<n;i++)
			{
				next[i]=i+1;
			}
			next[n-1]=-1;
		}

		bool isEmpty(int sn)
		{
			if(front[sn]==-1)
			{
				return true;
			}
			return false;
		}

		bool isFull()
		{
			if(free==-1)
			{
				return true;
			}
			return false;
		}
		void enqueue(int item,int sn)
		{
			if(isFull())
			{
				return ;
			}
			int i=free;
			arr[free]=item;
			free = next[i];
			if(rear[sn]==-1)
			{
				next[i]=-1;
				rear[sn]=i;
				front[sn]=i;
			}
			else
			{
				next[rear[sn]]=i;
				rear[sn]=i;
				next[i]=-1;
			}
			
			return ;
		}
		int dequeue(int sn)
		{
			if(isEmpty(sn))
			{
				return -1;
			}
			int output = front[sn];
			if(front[sn]==rear[sn])
			{
				front[sn]=-1;
				rear[sn]=-1;
			}
			else
			{
				front[sn]=next[output];
			}
			
			int i= free;
			free = output;
			next[output]=i;
			return arr[output];
		}

		~k_queue()
		{
			delete[] front,rear,arr,next;
		}

};

int main()
{
	int n,k;
	cin >> n >> k;
	k_queue Q(n,k);
	int q;
	cin >> q;
	while(q--)
	{
		string input;
		cin >> input;
		if(input=="enqueue")
		{
			int sn,item;
			cin >> item >> sn;
			Q.enqueue(item,sn);
		}
		else
		{
			int sn;
			cin >> sn;
			cout << Q.dequeue(sn) << endl;
		}
	}
	return 0;

}