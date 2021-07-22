//Given a sorted dictionary of an alien language, find order of characters

// Input:  words[] = {"baa", "abcd", "abca", "cab", "cad"}
// Output: Order of characters is 'b', 'd', 'a', 'c'
// Note that words are sorted and in the given language "baa" 
// comes before "abcd", therefore 'b' is before 'a' in output.
// Similarly we can find other orders.

// Input:  words[] = {"caa", "aaa", "aab"}
// Output: Order of characters is 'c', 'a', 'b'



// The idea is to create a graph of characters and then find topological sorting of the created graph. Following are the detailed steps.

// 1) Create a graph g with number of vertices equal to the size of alphabet in the given alien language. For example, if the alphabet size is 5, then there can be 5 characters in words. 
//Initially there are no edges in graph.

// 2) Do following for every pair of adjacent words in given sorted array.
// …..a) Let the current pair of words be word1 and word2. One by one compare characters of both words and find the first mismatching characters.
// …..b) Create an edge in g from mismatching character of word1 to that of word2.

// 3) Print topological sorting of the above created graph



#include<bits/stdc++.h>
using namespace std;

void top_sort(map<int,vector<int>>& adj,int start,vector<bool>& visited,vector<char>& stack)
{
	visited[start]=true;
	//explore it's neighbours
	for(int i=0;i<adj[start].size();i++)
	{
		int next = adj[start][i];
		if(visited[next]==true)
		{
			continue;
		}
		top_sort(adj,next,visited,stack);
	}
	stack.push_back(start + 'a');
	return ;
}

void solve(map<int,vector<int>>& adj,vector<bool>& visited)
{

	vector<char> stack;
	for(int i=0;i<26;i++)
	{
		if(visited[i]==false)
		{
			top_sort(adj,i,visited,stack);
		}
	}
	while(stack.size()!=0)
	{
		cout << stack.back() << " ";
		stack.pop_back();
	}
	cout << endl;
	return ;
}


int main()
{
	int n;
	cin >> n;
	vector<string> input;
	for(int i=0;i<n;i++)
	{
		string temp;
		cin >> temp;
		input.push_back(temp);
	}
	map<int,vector<int> > adj;// directed graph
	vector<bool> visited;
	visited.assign(26,true);
	for(int i=0;i<n-1;i++)
	{
		string first = input[i];
		string second = input[i+1];
		// we will find  the first mismatch and add edge to the graph
		for(int j=0;j<min(first.size(),second.size());j++)
		{
			if(first[j]!=second[j])
			{
				// add edge to our graph
				adj[first[j]-'a'].push_back(second[j]-'a');// direct edge
				visited[first[j]-'a']=false;
				visited[second[j]-'a']=false;
				break;
			}
		}
	}
	solve(adj,visited);
}