#include<bits/stdc++.h>
using namespace std;


int solve_2(int input[],int size,int x,int* ptr,int j,int count)
{
	if(size==1)
	{
		if(input[0]==x)
		{
			ptr[j]=count;
			return j+1 ;
		}
		return j;
	}
	if(input[0]==x)
	{
		ptr[j]=count;
		j+=1;
	}
	int k=solve_2(input+1,size-1,x,ptr,j,count+1);
	return k;
}

int solve(int input[],int size,int x,int output[])
{
	return solve_2(input,size,x,output,0,0);
	

}

int main()
{
	int output[10];
	int arr[] = {9,8,0,8};
	cout << solve(arr,5,8,output);
	return 0;
}