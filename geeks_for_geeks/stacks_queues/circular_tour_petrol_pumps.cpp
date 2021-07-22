#include<bits/stdc++.h>
using namespace std;

// problem - https://www.geeksforgeeks.org/find-a-tour-that-visits-all-stations/
// O(n) approach using queue
int solve2(vector<int>& petrol,vector<int>& dist,int n)
{
	int front = 0;
	int rear = 0;
	int cur_petrol = 0;
	// now we will include the first pump
	cur_petrol += petrol[rear];
	// i have to move to next pump
	cur_petrol -= dist[rear];
	rear+=1;
	// if cur_petrol < 0 we have to find new pump to start
	while(rear!=front || cur_petrol < 0)
	{
		while(cur_petrol < 0 && front!=rear)
		{
			// remove pump
			cur_petrol -= petrol[front];
			cur_petrol += dist[front];
			front = (front+1)%n;
			if(front==0)// we have already checked keeping first pump as start(all pumps have been explored)
			{
				return -1;
			}
		}
		// if cur_petrol >=0 
		cur_petrol += petrol[rear];
		cur_petrol -= dist[rear];
		rear = (rear+1)%n;
	}
	return front;

}


int solve(vector<int>& petrol,vector<int>& dist,int n)
{
	// this is n^2 approach
	// at each petrol pump we will check whether it is possible to make a circular tour
	for(int i=0;i<n;i++)
	{
		int cur_petrol = 0;
		int j=i;
		do
		{	
			cur_petrol+=petrol[j];
			cur_petrol-=dist[j];
			j++;
			if(j==n)
			{
				j=0;
			}
		}while(j<n && j!=i && cur_petrol >=0);
		if(j==i)
		{
			return i;
		}
	}
	return -1;
}
int main()
{
	int n;
	cin >> n;
	vector<int> petrol(n);
	vector<int> dist(n);
	for(int i=0;i<n;i++)
	{
		cin >> petrol[i];
	}
	for(int i=0;i<n;i++)
	{
		cin >> dist[i];
	}
	cout << solve(petrol,dist,n) << endl;
	cout << solve2(petrol,dist,n) << endl;
	return 0;
}