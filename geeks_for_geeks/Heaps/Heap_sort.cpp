#include<bits/stdc++.h>
using namespace std;

// time complexity O(n)(build tree) + O(nlogn)(deleting n nodes)
// Heap sort is inplace,unstable,O(nlogn)

void swap(int& a,int& b)
{
	int temp = a;
	a = b;
	b = temp;
	return ;
}

//top-down approach
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
		swap(arr[largest],arr[i]);
		heapify(arr,n,largest);
	}
}


void build_heap(int* arr,int n)
{
	int startIndex = (n/2)-1;
	for(int i=startIndex;i>=0;i--)
	{
		heapify(arr,n,i);
	}
}
void heap_sort(int* arr,int n)
{
	//build max_heap
	build_heap(arr,n);
	for(int i=n-1;i>0;i--)
	{
		swap(arr[0],arr[i]);
		heapify(arr,i,0);
	}
	return ;
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
	heap_sort(arr,n);
	for(int i=0;i<n;i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}