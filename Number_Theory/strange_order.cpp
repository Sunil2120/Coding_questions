// refer notes
#include<bits/stdc++.h>
using namespace std;


int main()
{
	int n;
	cin >> n;
	bool* arr = new bool[n+1];
	for(int i=0;i<=n;i++)
	{
		arr[i]=true;
	}
	for(int i=n;i>=1;i--)
	{
		vector<int> temp;
		if(arr[i]==false)
		{
			continue;
		}
		if(arr[i]==true)
		{
			int su = i;
			arr[i]=false;
			temp.push_back(i);
			for(int j=2;j*j<=i;j++)
			{
				if(su%j == 0)
				{
					for(int k=1;k*j<=i;k++)
					{
						if(arr[k*j]==true)
						{
							arr[k*j]=false;
							temp.push_back(k*j);
						}
					}
					while(su%j==0)
					{
						su=su/j;
					}
				}
			}
			if(su!=1)
			{
				for(int k=1;k*su<=i;k++)
				{
					if(arr[k*su]==true)
					{
						arr[k*su]=false;
						temp.push_back(k*su);
					}
				}
			}
		}
		sort(temp.begin(),temp.end());
		while(temp.size()!=0)
		{
			cout << temp.back() << " ";
			temp.pop_back();
		}
	}
	cout << endl;
	delete[] arr;
	return 0;
}