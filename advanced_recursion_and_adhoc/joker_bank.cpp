// destroying array problem using disjoint set
#include<bits/stdc++.h>
using namespace std;


int getparent(int* parent,int index)
{
	if(parent[index]==index)// root parent
	{
		return index;
	}
	return getparent(parent,parent[index]);
}


int main()
{
	int n;
	cin >> n;
	vector<int> output;
	int* input = new int[n+1];
	int* destroy = new int[n+1];
	int* parent = new int[n+1];
	int* visited = new int[n+1];
	int* size = new int[n+1];
	int* result = new int[n+1]();
	for(int i=1;i<=n;i++)
	{
		cin >> input[i];
		parent[i]=i;
		visited[i]=false;
		size[i]=1;
	}
	for(int i=n;i>=1;i--)
	{
		cin >> destroy[i];
	}
	int  max_ = 0;
	output.push_back(max_);
	for(int i=1;i<n;i++)
	{
		int cur = destroy[i];
		visited[cur]=true;
		int p = cur;
		result[p] = input[cur];
		// checking left
		if(cur-1 >=1)
		{
			if(visited[cur-1]==true)
			{
				p = getparent(parent,cur-1);
				parent[cur]=p;
				size[p]+=1;
				result[p]+=input[cur];
			}
		}
		if(cur+1 <= n)
		{
			if(visited[cur+1]==true)
			{
				int q = getparent(parent,cur);
				parent[cur+1]=q;
				size[q]+=1;
				result[q]+=result[cur+1];
			}
		}
		
		if(result[p] > max_)
		{
			max_ = result[p];
		}
		output.push_back(max_);
	}
	while(output.size()!=0)
	{
		cout << output.back() << endl;
		output.pop_back();
	}
	delete[] input;
	delete[] result;
	delete[] visited;
	delete[] size;
	delete[] parent;
	delete[] destroy;
	return 0;

}