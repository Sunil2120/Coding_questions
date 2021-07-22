#include<bits/stdc++.h>
using namespace std;



void solve(int n,int k,int x,int* input)
{
	// we will keep an array of size 1000
	int* output = new int[1000+1](); // this array has the count of how many times number has occured
	for(int i=0;i<n;i++)
	{
		output[input[i]]+=1;
	}
	for(int i=0;i<=32;i++)
	{
		cout << output[i] << " ";
	}
	cout << endl ;
	int* output2 = new int[1000+1]();
	int count =0;
	for(int i=1;i<=1000;i++)
	{
		if(output[i]!=0)
		{
			count+=output[i];
			if(output[i]%2==0)
			{
				output2[i]=output[i]/2;
				output2[i^x]+=output[i]/2;
			}
			else
			{
				int temp = count - output[i];
				if(temp%2==0)
				{

					output2[i] = output[i]/2;
					output2[i^x]+=output[i] - (output[i]/2);
					
				}
				else
				{
					output2[i^x]+=output[i]/2;
					output2[i]=output[i]-(output[i]/2);
				}

			}

		}
		
	}

	for(int i=0;i<=32;i++)
	{
		cout << output[i] << " ";
	}
	cout << endl ;
	int ma=0;
	int mi=0;
	count = 0;
	for(int s=1;s<k-1;s++)
	{
		count = 0;
		for(int i=0;i<=1000;i++)
		{
			if(output[i]!=0)
			{
				count+=output[i];
				if(output[i]%2==0)
				{
					output2[i]=output[i]/2;
					output2[i^x]+=output[i]/2;
				}
				else
				{
					int temp = count - output[i];
					if(temp%2==0)
					{

						output2[i] = output[i]/2;
						output2[i^x]+=output[i] - (output[i]/2);
						
					}
					else
					{
						output2[i^x]+=output[i]/2;
						output2[i]=output[i]-(output[i]/2);
					}

				}

			}

		}

		// for(int i=0;i<=1000;i++)
		// {
		// 	if(output2[i]>0)
		// 	{
		// 		mi=i;
		// 		break;
		// 	}
		// }
		// for(int j=1000;j>=0;j--)
		// {
		// 	if(output2[j]>0)
		// 	{
		// 		ma=j;
		// 		break;
		// 	}
		// }
		// cout << ma << " " << mi << endl;


	}
	
	ma=0;
	mi=0;
	for(int i=0;i<=1000;i++)
	{
		if(output2[i]>0)
		{
			mi=i;
			break;
		}
	}
	for(int j=1000;j>=0;j--)
	{
		if(output2[j]>0)
		{
			ma=j;
			break;
		}
	}

	cout << ma << " " << mi << endl;
	return ;
}

int main()
{
	int n,k,x;
	cin >> n >> k >> x;
	int* input = new int[n]();
	for(int i=0;i<n;i++)
	{
		cin >> input[i];
	}
	solve(n,k,x,input);

	return 0;
}