// Given a sequence of words, and a limit on the number of characters that can be put in one line (line width). Put line breaks in the given sequence such that the lines are printed neatly.
//  Assume that the length of each word is smaller than the line width.

// The word processors like MS Word do task of placing line breaks. The idea is to have balanced lines. In other words, 
// not have few lines with lots of extra spaces and some lines with small amount of extra spaces.
#include<bits/stdc++.h>
using namespace std;

// o(n2) and o(n2) auxillary space
void solve(vector<string>& input,int n,int M)
{
	// cost[i][j] represents cost fo placing words from index i to j in a single line
	int** cost = new int*[n];
	for(int i=0;i<n;i++)
	{
		cost[i]= new int[n]();
	}
	int extra[n][n];
	for(int i=0;i<n;i++)
	{
		extra[i][i]= (M - input[i].length());
		for(int j=i+1;j<n;j++)
		{
			extra[i][j]= extra[i][j-1] - input[j].length() - 1;
		}
	}

	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			if(extra[i][j] < 0)
			{
				cost[i][j]=INT_MAX;
			}
			else
			{
				cost[i][j]=extra[i][j]*extra[i][j];
			}
		}
	}

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout << cost[i][j] << " ";
		}
		cout << endl;
	}
	
	int* min_cost = new int[n];// stores min_cost  to place words from i to n-1
	int* places = new int[n];
	for(int i=n-1;i>=0;i--)
	{
		int j = n-1;
		if(cost[i][j]!=INT_MAX)// we can place words from i to j in single line
		{
			min_cost[i] = cost[i][j];
			places[i]=j+1;
			continue;
		}
		int min_value = INT_MAX;
		int min_i = -1;
		// splitting at j
		while(j!=i)
		{
			if(cost[i][j-1]!=INT_MAX)
			{
				int temp = cost[i][j-1] + min_cost[j];
				if(temp < min_value)
				{
					min_value = temp;
					min_i = j-1;
				}
			}
			j--;
		}
		min_cost[i]=min_value;
		places[i]=min_i+1;	
	}
	for(int i=0;i<n;i++)
	{
		cout << min_cost[i] << " ";
	}
	cout << endl;
	for(int i=0;i<n;i++)
	{	
		cout << places[i] << " ";
	}
	cout << endl;
	//initial
	int check = 0;
	for(int i=0;i<places[0];i++)
	{
		check = 1;
		cout << input[i] << " ";
	}
	if(check == 1)
	{
		cout << endl;
	}
	for(int i=0;i<n-1;i++)
	{
		check = 0;
		if(places[i]==n)
		{
			break;
		}
		for(int j=places[i];j<places[i+1];j++)
		{
			check = 1;
			cout << input[j] << " ";
		}
		if(check==1)
		{
			cout << endl;
		}
	}
	delete[] min_cost;
	delete[] places;
	for(int i=0;i<n;i++)
	{
		delete[] cost[i];
	}
	delete[] cost;
	return ;


}

// o(n2) and o(n) auxillary space
void solve1(vector<string>& input,int n,int M)
{
	int* min_cost = new int[n]();
	int* places = new int[n]();
	int* arr = new int[n]();
	for(int i=n-1;i>=0;i--)
	{
		//cout << "hello" << endl;
		arr[i]=(M - input[i].size());
		//cout << arr[i] << endl;
		for(int j=i+1;j<n;j++)
		{
			arr[j]=arr[j-1]-input[j].size()-1;
		}
		for(int j=i;j<n;j++)
		{
			if(arr[j] < 0)
			{
				arr[j]=INT_MAX;
			}
			else
			{
				arr[j]=arr[j]*arr[j];
			}
		}
		for(int j=i;j<n;j++)
		{
			cout << arr[j] << " ";
		}
		cout << endl;
		int j = n-1;
		if(arr[j]!=INT_MAX)// we can place words from i to j in single line
		{
			min_cost[i] = arr[j];
			places[i]=j+1;
			continue;
		}
		int min_value = INT_MAX;
		int min_i = -1;
		// splitting at j
		while(j!=i)
		{
			if(arr[j-1]!=INT_MAX)
			{
				int temp = arr[j-1] + min_cost[j];
				if(temp < min_value)
				{
					min_value = temp;
					min_i = j-1;
				}
			}
			j--;
		}
		min_cost[i]=min_value;
		places[i]=min_i+1;	
	}
	for(int i=0;i<n;i++)
	{
		cout << min_cost[i] << " ";
	}
	cout << endl;
	for(int i=0;i<n;i++)
	{
		cout << places[i] << " ";
	}
	cout << endl;
	int check = 0;
	for(int i=0;i<places[0];i++)
	{
		check = 1;
		cout << input[i] << " ";
	}
	if(check==1)
	{
		cout << endl;
	}
	for(int i=0;i<n-1;i++)
	{
		check = 0;
		if(places[i]==n)
		{
			break;
		}
		for(int j=places[i];j<places[i+1];j++)
		{
			check = 1;
			cout << input[j] << " ";
		}
		if(check==1)
		{
			cout << endl;
		}
	}
	delete[] arr;
	delete[] places;
	delete[] min_cost;
	return ;
}

int main()
{
	int n;
	cin >> n;
	vector<string> input;
	for(int i=0;i<n;i++)
	{
		string value;
		cin >> value;
		input.push_back(value);
	}
	int k;
	cin >> k;
	solve1(input,n,k);
}