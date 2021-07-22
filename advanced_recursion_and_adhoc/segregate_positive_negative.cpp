#include<bits/stdc++.h>
using namespace std;


//The above problem can be easily solved if O(n) extra space is allowed. It becomes interesting due to the limitations that O(1) extra space and order of appearances.
//The idea is to process array from left to right. While processing, find the first out of place element in the remaining unprocessed array. An element is out of place if it is negative and at odd index, or it is positive and at even index. Once we find an out of place element, we find the first element after it with opposite sign. We right rotate the subarray between these two elements (including these two).


// always cur we will greater than out_of_place
void right_rotate(int* arr,int out_of_place,int cur)
{
	int temp = arr[cur];
	for(int i= cur;i>out_of_place;i--)
	{
		arr[i]=arr[i-1];
	}
	arr[out_of_place]=temp;

	return ;
}



// time-complexity o(n) and extra space is o(1)

// negative element should be in even index
// positive element should be in odd index
int main()
{
	int n;
	cin >> n;
	int* arr = new int[n];
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
	}
	int out_of_place = -1;
	// negative at even index
	// positive at odd index
	for(int i=0;i<n;i++)
	{

		// we will find the opposite sign element for out_of_place
		if(out_of_place >=0)
		{
			if((arr[out_of_place] < 0 && arr[i] >=0) || (arr[out_of_place] >=0 && arr[i] < 0))
			{
				right_rotate(arr,out_of_place,i);
				// now new out_of_place will be 2 steps ahead
				if((i - out_of_place) >=2)
				{
					out_of_place = out_of_place + 2;
				}
				else
				{
					out_of_place = -1;
				}
			}

		}
		if(out_of_place == -1)
		{
			if( (arr[i]>=0 && (i%2)==0) || (arr[i]<0 && (i%2)!=0))
			{
				out_of_place = i;
			}
		}
	}

	for(int i=0;i<n;i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}


// o(n) time and o(n) space
// int main()
// {
// 	int n;
// 	cin >> n;
// 	int* arr = new int[n];
// 	vector<int> positive;
// 	vector<int> negative;
// 	for(int i=0;i<n;i++)
// 	{
// 		cin >> arr[i];
// 		if(arr[i] >= 0)
// 		{
// 			positive.push_back(arr[i]);
// 		}
// 		else
// 		{
// 			negative.push_back(arr[i]);
// 		}
// 	}
// 	int i= 0;
// 	int j = 0;
// 	int k = 0;
// 	while(i < negative.size() && j<positive.size())
// 	{
// 		arr[k++] = negative[i];
// 		i++;
// 		arr[k++]=positive[j];
// 		j++;
// 	}
// 	while(i < negative.size())
// 	{
// 		arr[k++]=negative[i];
// 		i++;
// 	}
// 	while(j < positive.size())
// 	{
// 		arr[k++]=positive[j];
// 		j++;
// 	}
// 	for(int i=0;i<n;i++)
// 	{
// 		cout << arr[i] << " ";
// 	}
// 	cout <<endl;
// 	return 0;


// }