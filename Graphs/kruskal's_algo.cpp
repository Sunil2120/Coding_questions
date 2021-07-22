#include<bits/stdc++.h>
using namespace std;

struct node
{
	int src=0;
	int dest=0;
	int weight=0;
};

bool compare(node a,node b)
{
	return a.weight < b.weight;//increasing
}


int getpath(int key,int* parent)
{
	if(parent[key]==key)//parent
	{
		return key;
	}
	return getpath(parent[key],parent);
}


node* solve(node* input,int V,int E)
{
	sort(input,input+E,compare);// +E because input has E elements
	node* output = new node[V-1];
	int* parent = new int[V];
	for(int i=0;i<V;i++)
	{
		parent[i]=i;
	}
	int count = 0;
	int i=0;
	while(count < V-1)// number of edges should be n-1 we are starting from 0
	{
		int src = getpath(input[i].src,parent);
		int dest = getpath(input[i].dest,parent);
		if(src!=dest)// they are in different connected components
		{
			output[count]=input[i];
			count+=1;
			// we have to set one of the vertex parent
			parent[src]=dest;
		}
		i+=1;
	}
	delete[] parent;
	return output;
}

int main()
{
	int V,E;
	cin >> V >> E;
	node* input = new node[E];
	for(int i=0;i<E;i++)
	{
		int start,end,w;
		cin >> start >> end >> w;
		input[i].src = start;
		input[i].dest = end;
		input[i].weight = w;
	}
	node* result = solve(input,V,E);
	for(int i=0;i<V-1;i++)
	{
		if(result[i].src < result[i].dest)
		{
			cout << result[i].src << " " << result[i].dest << " " << result[i].weight << endl;
		}
		else
		{
			cout << result[i].dest << " " << result[i].src << " " << result[i].weight << endl;
		}
	}
	delete[] input;
	return 0;

}