#include<bits/stdc++.h>
using namespace std;


bool ispossible(int rx,int ry,int m,int n)
{
	if(rx < 0 || rx>=m || ry <0 || ry>=n)
	{
		return false;
	}
	return true;
}

bool helper(char** arr,string search,int cur_index,int x,int y,int m,int n,int ax,int ay)
{
	if(cur_index==search.size())
	{
		return true;
	}

	if(ispossible(x+ax,y+ay,m,n) && arr[x+ax][y+ay]==search[cur_index])
	{
		return helper(arr,search,cur_index+1,x+ax,y+ay,m,n,ax,ay);
	}
	return false;
	
}


void solve(char** arr,string search,int m,int n)
{
	int row[8]={-1,1,0,0,-1,1,-1,1};
	int col[8]={0,0,-1,1,-1,1,1,-1};
	int check = 0;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(arr[i][j]==search[0])
			{
				if(search.size()==1)
				{
				    check = 1;
					cout << i << " " << j << ",";
				}
				else
				{
					bool temp1 = false;
					for(int k=0;k<8;k++)
					{
						int rx = i+row[k];
						int ry = j+col[k];
						if(ispossible(rx,ry,m,n) && arr[rx][ry]==search[1])
						{
							bool temp = helper(arr,search,2,rx,ry,m,n,row[k],col[k]);
							temp1 = temp1 || temp;
						}
					}
					if(temp1==true)
					{
					    check = 1;
						cout << i << " " << j << ",";
					}
				}
				
				
			}
		}
	}
	if(check==0)
    {
        cout << -1;
    }
    cout << endl;
	return ;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int m,n;
    	cin >> m >> n;
    	char** arr = new char*[m];
    	for(int i=0;i<m;i++)
    	{
    		arr[i]=new char[n];
    		for(int j=0;j<n;j++)
    		{
    			cin >> arr[i][j];
    		}
    	}
    	string search;
    	cin >> search;
    	solve(arr,search,m,n);
    	for(int i=0;i<m;i++)
        {
            delete[] arr[i];
        }
        delete[] arr;
    }

	//cout << helper(arr,search,2,0,9,m,n,0,1) << endl;
}