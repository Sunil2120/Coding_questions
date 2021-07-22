#include<bits/stdc++.h>
using namespace std;


struct node
{
	int first;
	int second;
	int index;

};


bool compare(node a,node b)
{
	return a.second < b.second;// increasing order
}


void  update(int* BIT,int index,int value,int n)
{
	for(int i=index;i<=n;i+=(i&(-i)))
	{
		BIT[i]+=value;
	}
}

int query(int* BIT,int index)
{
	int count = 0;
	for(int i=index;i>0;i-=(i&(-i)))
	{
		count+=BIT[i];
	}
	return count;
}


int main()
{
	int n;
	cin >> n;
	int* arr = new int[n+1]();
	for(int i=1;i<=n;i++)
	{
		cin >> arr[i];
	}
	int q;
	cin >> q;
	node* output = new node[q];
	for(int i=0;i<q;i++)
	{
		cin >> output[i].first >> output[i].second;
		output[i].index = i;
	}
	sort(output,output+q,compare);
	int* BIT = new int[n+1]();
	int* elements = new int[1000000];
	for(int i=0;i<1000000;i++)
	{
		elements[i]=-1;
	}
	int* ans = new int[q]();
	int total = 0;
	int k = 0;
	for(int i=1;i<=n;i++)
	{
		if(elements[arr[i]]!=-1)// element has already present
		{
			update(BIT,elements[arr[i]],-1,n);

		}
		else// present element is the unique element
		{
			total++;
			update(BIT,i,1,n);
			elements[arr[i]]=i;
		}
		//cout << "total" << " " << total << endl;

		while(k<q && output[k].second==i)
		{

			ans[output[k].index]= total - query(BIT,output[k].first-1);
			//cout << "test" << " " << output[k].first << " " << output[k].second << " " << ans[output[k].index] << endl;
			k++;
		}

	}

	for(int i=0;i<q;i++)
	{
		cout << ans[i] << endl;
	}

	return 0;

}