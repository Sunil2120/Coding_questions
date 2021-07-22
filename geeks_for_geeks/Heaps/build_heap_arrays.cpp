#include<bits/stdc++.h>
using namespace std;



//building heap tree using heapify method 
// time complexity o(n)
// space complexity o(logn)

void swap(int& a,int& b)
{
	int temp = a;
	a = b;
	b=temp;
	return ;
}

void heapify(int* arr,int n,int i)
{
	int largest = i;
	int l = 2*i + 1;
	int r = 2*i + 2;
	if(l<n && arr[l] > arr[largest])
	{
		largest = l;
	}
	if(r<n && arr[r] > arr[largest])
	{
		largest = r;
	}
	if(largest!=i)
	{
		//swap
		int temp = arr[i];
		arr[i]=arr[largest];
		arr[largest]=temp;
	}
	if(largest!=i)
		heapify(arr,n,largest);

	return ;
}
//max_heap
//top-down approach(nlogn)
void build_heap(int* arr,int n)
{
	//get the non-leaf last node
	int startIndex = (n/2)-1;
	for(int i=startIndex;i>=0;i--)
	{
		heapify(arr,n,i);
	}
	return ;

}

//top-down approch(logn)
void delete_node(int* arr,int& n)
{
	arr[0]=arr[n-1];
	n=n-1;
	heapify(arr,n,0);

}

//bottom-up approach O(logn)
void heapify2(int* arr,int n,int i)
{
	int parent = (i-1)/2;
	if(parent >=0)
	{
		if(arr[i] > arr[parent])//max heap
		{
			swap(arr[i],arr[parent]);
			heapify2(arr,n,parent);
		}
	}
	return ;

}

//inserting a node this is bottom-up approach O(logn)

void insert_node(int* arr,int& n,int key)
{
	n=n+1;
	arr[n-1]=key;
	heapify2(arr,n,n-1);
}
void print_heap(int* arr,int n)
{
	for(int i=0;i<n;i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main()
{
	int n;
	cin >> n;
	int* arr = new int[n];
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
	}
	build_heap(arr,n);
	print_heap(arr,n);
	delete_node(arr,n);
	print_heap(arr,n);
	int el;
	cin >> el;
	insert_node(arr,n,el);
	print_heap(arr,n);
	return 0;
}
