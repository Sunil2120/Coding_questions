#include<bits/stdc++.h>
#define N 10
using namespace std;



bool isValidVertically(char grid[][10],vector<string> input,int index,int row,int col)
{
	//cout << "isValidVertically" << endl;
	for(int i=row;i<row + input[index].size();i++)
	{
		if(grid[i][col]=='-')
		{
			continue;
		}
		else if(grid[i][col]=='+')
		{
			return false;
		}
		else if(grid[i][col] != input[index][i-row])
		{
			return false;
		}

	}
	return true;
}

bool isValidHorizontally(char grid[][10],vector<string> input,int index,int row,int col)
{
	//cout << "isValidHorizontally" << endl;
	for(int i=col;i< col + input[index].size();i++)
	{
		if(grid[row][i]=='-')
		{
			continue;
		}
		else if(grid[row][i]=='+')
		{
			return false;
		}
		else if(grid[row][i]!= input[index][i-col])
		{
			return false;
		}
	}
	return true;
}


void setvertically(char grid[][10],vector<string> input,int index,int row,int col,vector<bool>& check)
{
	//cout << "setvet" << endl;
	for(int i=row;i< row + input[index].size();i++)
	{
		if(grid[i][col]=='-')
		{
			grid[i][col]=input[index][i-row];
			check.push_back(true);
		}
		else
		{
			check.push_back(false);
		}
		
	}
}

void setHorizontally(char grid[][10],vector<string> input,int index,int row,int col,vector<bool>& check)
{
	//cout << "setHor" << endl;
	for(int i=col;i< col + input[index].size();i++)
	{
		if(grid[row][i]=='-')
		{
			grid[row][i]=input[index][i-col];
			check.push_back(true);
		}
		else
		{
			check.push_back(false);
		}
		
	}
}

void  resetvertically(char grid[][10],vector<string> input,int index,int row,int col,vector<bool>& check)
{
	//cout  << "resetvertically"<< endl;
	for(int i=row;i< row + input[index].size();i++)
	{
		if(check[i-row]==true)
		{
			grid[i][col]='-';
		}
	}
}

void resetHorizontally(char grid[][10],vector<string> input,int index,int row,int col,vector<bool>& check)
{
	//cout  << "resetHorizontally"<< endl;
	for(int i=col;i< col + input[index].size();i++)
	{
		if(check[i-col]==true)
		{
			grid[row][i]='-';
		}
	}
}


bool solve_puzzle( char grid[][10],vector<string> input,int index)
{
	if(index>= input.size())
	{
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
			{
				cout << grid[i][j] << " ";
			}
			cout << endl;
		}
		return true;
	}

	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			if(grid[i][j]=='-' || grid[i][j]==input[index][0])
			{
				//cout << i << " " << j << endl;
				//cout << isValidVertically(grid,input,index,i,j) << endl;
				if(isValidVertically(grid,input,index,i,j))
				{
					//cout << i << " " << j << endl;
					vector<bool> check;
					//memset(check,false,N*sizeof(bool));
					setvertically(grid,input,index,i,j,check);
					//cout << "setdonev" << endl;
					if(solve_puzzle(grid,input,index+1))
					{
						return true;
					}
					resetvertically(grid,input,index,i,j,check);
				}
				//cout << isValidHorizontally(grid,input,index,i,j) << endl;
				else if(isValidHorizontally(grid,input,index,i,j))
				{
					//cout << i << " " << j << endl;
					vector<bool> check;
					//memset(check,false,N*sizeof(bool));
					setHorizontally(grid,input,index,i,j,check);
					//cout << "setdoneh" << endl;
					if(solve_puzzle(grid,input,index+1))
					{
						return true;
					}
					resetHorizontally(grid,input,index,i,j,check);
				}
			}
		}
	}
	return false;
}


int main()
{
	char grid[10][10];
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			cin >> grid[i][j];
		}
	}
	vector<string> input;
	string suni;
	string a;
    cin >> suni;
    int temp=0;
    for(int i=0;i<suni.size();i++)
    {
        if(suni[i]==';')
        {
           input.push_back(a);
           a="";
        }
        else
        {
        	a.push_back(suni[i]);
        }
    }
   
   input.push_back(a);
	solve_puzzle(grid,input,0);
	return 0;

}