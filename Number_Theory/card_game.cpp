// find total number of subarray in given array whose product is divisible by given k
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int n,k;
	cin >> n >> k;
	ll* arr = new ll[n];
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
	}
	vector< pair<int,int> > vp;
	// getting the prime factors of k
	int temp_k=k;
	for(int i=2;i*i<=k;i++)
	{
		if(temp_k%i==0)
		{
			int count = 0;
			while(temp_k % i==0)
			{
				count+=1;
				temp_k=temp_k/i;
			}
			vp.push_back(make_pair(i,count));	
		}
		
	}
	if(temp_k!=1)
	{
		vp.push_back(make_pair(temp_k,1));
	}
	
	vector< pair<int,int> > vq = vp;
	for(int i=0;i<vp.size();i++)
	{
		vq[i].second = 0;
	}

	int j=0;
	int ans = 0;
	for(int i=0;i<n;i++)
	{
		for(int z=0;z<vp.size();z++)
		{
			if(arr[i] % vp[z].first == 0)
			{
				temp_k = arr[i];
				int count = 0;
				while(temp_k % vq[z].first ==0)
				{
					count+=1;
					temp_k=temp_k/vq[z].first;
				}
				vq[z].second+=count;
			}
			
		}

		while(j<=i)
		{
			int z;
			for(z=0;z<vp.size();z++)
			{
				if(vp[z].second > vq[z].second)// it is not divisible
				{
					break;
				}
			}

			if(z!=vp.size())
			{
				break;
			}
			// we have got a num divisible by k
			ans += n - i;
			// we should prime factor contribution of arr[j] in vq
			for(int z=0;z<vq.size();z++)
			{
				if(arr[j] % vp[z].first == 0)
				{
					int count = 0;
					temp_k = arr[j];
					while(temp_k% vq[z].first == 0)
					{
						count++;
						temp_k = temp_k/vq[z].first;
					}
					vq[z].second-=count;
				}
				
			}
			j++;
		}
		cout << ans << endl;
		return 0;
	}


}