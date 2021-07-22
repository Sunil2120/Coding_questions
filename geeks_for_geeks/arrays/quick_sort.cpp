#include<bits/stdc++.h>
using namespace std;

int partition(int* arr,int start,int end)
{
	int key = arr[start];
	// we are finding elements less than key
	int count = 0;
	for(int i=start+1;i<=end;i++)
	{
		if(arr[i] <= key)
		{
			count+=1;
		}
	}
	// now we are placing key to its correct position
	int temp = arr[start];
	arr[start]=arr[start+count];
	arr[start+count]=temp;

	int i = start;
	int j = end;
	while(i < (start+count)  && j > (start+count))
	{
		if(arr[i] <= arr[start+count])
		{
			i+=1;
		}
		if(arr[j] > arr[start+count])
		{
			j--;
		}
		if(arr[i] > (start+count)  && arr[j] <= (start+count))
		{
			int temp1 = arr[i];
			arr[i]=arr[j];
			arr[j]=temp1;
			i+=1;
			j--;
		}
	}
	return (start+count);// position of the key

}

void quick_sort(int* arr,int start,int end)
{
	if(start>=end)
	{
		return ;
	}
	if(start < end)
	{
		int index = partition(arr,start,end);
		quick_sort(arr,start,index-1);
		quick_sort(arr,index+1,end);
	}
	return;
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
	quick_sort(arr,0,n-1);
	for(int i=0;i<n;i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}