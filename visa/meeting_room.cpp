#include<bits/stdc++.h>
using namespace std;

struct node
{
	int index;
	pair<int,int> interval;
};
typedef struct node Node;



bool compare(Node* a,Node* b)
{
	return a->interval.second < b->interval.second;
}


int main()
{
	int n;
	cin >> n;
	vector<Node*> input;
	for(int i=0;i<n;i++)
	{
		int start,end;
		cin >> start >> end;
		Node* temp = new Node();
		temp->index = i;
		temp->interval = make_pair(start,end);
		input.push_back(temp);
	}
	sort(input.begin(),input.end(),compare);
	cout << input[0]->index << " ";
	int prev = input[0]->interval.second;
	for(int i=1;i<n;i++)
	{
		if(input[i]->interval.first >= prev)
		{
			prev = input[i]->interval.second;
			cout << input[i]->index;
		}
	}
	cout << endl;
	return 0;
	

}