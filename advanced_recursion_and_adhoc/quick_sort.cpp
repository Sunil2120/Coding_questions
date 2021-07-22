#include<bits/stdc++.h>
using namespace std;


// void swap(int a,int b)
// {
// 	int temp=0;
// 	temp=a;
// 	a=b;
// 	b=temp;
// }

int partition(int input[],int start,int end)
{
	int key = input[start];
	int count =0;
	for(int i=start+1;i<=end;i++)
	{
		if(input[i]<key)
		{
			count+=1;
		}
	}
	int temp1=input[start+count];
	input[start]=temp1;
	input[start+count]=key;
	int i=start,j=end;
	while(i<(start+count) && j>(start+count))
	{
		if(input[i] < key)
		{
			i++;
		}
		if(input[j] >= key)
		{
			j--;
		}
		if(input[i] >=key && input[j] < key)
		{
			int temp=input[i];
			input[i]=input[j];
			input[j]=temp;
			i++;
			j--;
		}
	}
	return (start+count);

}

void QS(int input[],int start,int end)
{
	if(start < end)
	{
		int c = partition(input,start,end);
		QS(input,start,c-1);
		QS(input,c+1,end);
	}
	return ;
}



int main()
{
	int arr[10]={2,3,1,5,3,2};
	QS(arr,0,5);
	for(int i=0;i<6;i++)
	{
		cout << arr[i] << endl;
	}
	return 0;
}