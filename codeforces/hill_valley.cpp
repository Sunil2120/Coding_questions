#include<bits/stdc++.h>
using namespace std;


int solve(int* arr,int n)
{
	//0 is valley
	//1 is hill
	int* temp=new int[n];
	for(int i=0;i<n;i++)
	{
		temp[i]=-1;
	}
	for(int i=1;i<n-1;i++)
	{
		if(arr[i]>arr[i-1] && arr[i]>arr[i+1])
		{
			//hill
			temp[i]=1;
			continue;
		}
		if(arr[i]<arr[i-1] && arr[i]<arr[i+1])
		{
			temp[i]=0;
		}
	}
	int val=0;
	int hi=0;
	for(int i=1;i<n-1;i++)
	{
		if(temp[i]==0)
		{
			val++;
		}
		if(temp[i]==1)
		{
			hi++;
		}
	}
	int total=hi+val;
	cout << "total is" << total << endl;
	int minus=0;
	int ans=total;
	for(int i=1;i<n-1;i++)
	{
		int temp3=i;
		//make it equal to left
		int temp2=arr[i];
		arr[i]=arr[i-1];
		
		//cur
		if(i!=0 && i!=(n-1) && arr[i]>arr[i-1] && arr[i]>arr[i+1])//hill
		{
			if(temp[i]==-1)//we created one
			{
				//increase the minus
				minus--;
			}
		}
		else if(i!=0 && i!=(n-1)  && arr[i]<arr[i-1] && arr[i]<arr[i+1])//valley
		{
			if(temp[i]==-1)
			{
				minus--;
			}
		}
		else if(i!=0 && i!=(n-1) )
		{
			minus++;//we reduced one
		}

		i=i+1;
		//right
		//cur
		if(i!=0 && i!=(n-1) && arr[i]>arr[i-1] && arr[i]>arr[i+1])//hill
		{
			if(temp[i]==-1)//we created one
			{
				//increase the minus
				minus--;
			}
		}
		else if(i!=0 &&i!=(n-1)  && arr[i]<arr[i-1] && arr[i]<arr[i+1])//valley
		{
			if(temp[i]==-1)
			{
				minus--;
			}
		}
		else if(i!=0 && i!=(n-1) )
		{
			minus++;//we reduced one
		}

		i=i-2;
		//cur
		if(i!=0 && i!=(n-1) && arr[i]>arr[i-1] && arr[i]>arr[i+1])//hill
		{
			if(temp[i]==-1)//we created one
			{
				//increase the minus
				minus--;
			}
		}
		else if(i!=0 &&i!=(n-1)  && arr[i]<arr[i-1] && arr[i]<arr[i+1])//valley
		{
			if(temp[i]==-1)
			{
				minus--;
			}
		}
		else if(i!=0 && i!=(n-1) )
		{
			minus++;//we reduced one
		}
		cout << "left " << i << " " << minus << " " << ans <<  endl; 
		ans=min(ans,total-minus);
		minus=0;
		i=temp3;
		arr[i]=arr[i+1];
		
		//cur
		if(i!=0 && i!=(n-1) && arr[i]>arr[i-1] && arr[i]>arr[i+1])//hill
		{
			if(temp[i]==-1)//we created one
			{
				//increase the minus
				minus--;
			}
		}
		else if(i!=0 &&i!=(n-1)  && arr[i]<arr[i-1] && arr[i]<arr[i+1])//valley
		{
			if(temp[i]==-1)
			{
				minus--;
			}
		}
		else if(i!=0 && i!=(n-1) )
		{
			minus++;//we reduced one
		}

		i=i+1;
		//right
		//cur
		if(i!=0 && i!=(n-1) && arr[i]>arr[i-1] && arr[i]>arr[i+1])//hill
		{
			if(temp[i]==-1)//we created one
			{
				//increase the minus
				minus--;
			}
		}
		else if(i!=0 &&i!=(n-1)  && arr[i]<arr[i-1] && arr[i]<arr[i+1])//valley
		{
			if(temp[i]==-1)
			{
				minus--;
			}
		}
		else if(i!=0 && i!=(n-1) )
		{
			minus++;//we reduced one
		}

		i=i-2;
		//cur
		if(i!=0 && i!=(n-1) && arr[i]>arr[i-1] && arr[i]>arr[i+1])//hill
		{
			if(temp[i]==-1)//we created one
			{
				//increase the minus
				minus--;
			}
		}
		else if(i!=0 &&i!=(n-1)  && arr[i]<arr[i-1] && arr[i]<arr[i+1])//valley
		{
			if(temp[i]==-1)
			{
				minus--;
			}
		}
		else if(i!=0 && i!=(n-1) )
		{
			minus++;//we reduced one
		}
		ans=min(ans,total-minus);

		//revert
		arr[i]=temp2;
		i=temp3;
		cout << "left " << i << " " << minus  << " " << ans << endl; 


	}
	return ans;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		int* arr=new int[n]();
		for(int i=0;i<n;i++)
		{
			cin >> arr[i];
		}
		cout << solve(arr,n) << endl;
	}
	return 0;
}