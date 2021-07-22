#include<bits/stdc++.h>
using namespace std;


struct GraphNode
{
    int val;
    vector<GraphNode*> neighbours;
};
typedef GraphNode node;

GraphNode *buildGraph() 
{ 
    /* 
        Note : All the edges are Undirected 
        Given Graph: 
        1--2 
        | | 
        4--3 
    */
    GraphNode *node1 = new GraphNode(); 
    node1->val = 1; 
    GraphNode *node2 = new GraphNode(); 
    node2->val = 2; 
    GraphNode *node3 = new GraphNode(); 
    node3->val = 3; 
    GraphNode *node4 = new GraphNode(); 
    node4->val = 4; 
    vector<GraphNode *> v; 
    v.push_back(node2); 
    v.push_back(node4); 
    node1->neighbours = v; 
    v.clear(); 
    v.push_back(node1); 
    v.push_back(node3); 
    node2->neighbours = v; 
    v.clear(); 
    v.push_back(node2); 
    v.push_back(node4); 
    node3->neighbours = v; 
    v.clear(); 
    v.push_back(node3); 
    v.push_back(node1); 
    node4->neighbours = v; 
    return node1; 
}

void dfs(node* start,set<int>& visited)
{
    visited.insert(start->val);
    // explore it's neighbours
    cout << start->val << endl;
    for(int i=0;i<(start->neighbours).size();i++)
    {
        node* next = start->neighbours[i];
        if(visited.find(next->val)==visited.end())
        {
            dfs(next,visited);
        }
    }
    return ;
}

node* solve(node* root)
{
    map<node*,node*> hash;
    queue<node*> Q;
    node* temp = new node();
    temp->val = root->val;
    hash[root]=temp;
    Q.push(root);
    while(!Q.empty())
    {

        node* cur = Q.front();
        Q.pop();
        // explore neighbours
        for(int i=0;i<(cur->neighbours).size();i++)
        {
            node*next = cur->neighbours[i];
            if(hash[next]==NULL)//not visited yet
            {
                node* temp1 = new node();
                temp1->val = next->val;
                hash[next]=temp1;
                Q.push(next);
            }
            hash[cur]->neighbours.push_back(hash[next]);
        }
    }
    return hash[root];
}

int main()
{
    node* root = buildGraph();
    node* root1 = solve(root);
    set<int> visited;
    dfs(root,visited);
    cout << "next" << endl;
    visited.clear();
    dfs(root1,visited);
}