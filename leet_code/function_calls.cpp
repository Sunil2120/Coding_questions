#include<bits/stdc++.h>
using namespace std;


int main()
{
	int n;
	cin >> n;
	int* nums = new int[n];
	for(int i=0;i<n;i++)
	{
		cin >> nums[i];
	}

        int total = n;
        cout << total << endl;
        int large = 0;
        for(int i=0;i<n;i++)
        {
            large = max(large,nums[i]);
        }
        int count = 0;
        int temp = 2;
        while(large >= temp)
        {
            count+=1;
            temp = temp*2;
        }
        total+=count;
        for(int i=0;i<n;i++)
        {
            if(nums[i]&1)
            {
            	total+=1;
            }
        }
    cout << total << endl;
}