// refer tushar's video
#include<bits/stdc++.h>
using namespace std;


struct point
{
	int x;
	int y;

};
typedef struct point point;

double distance(point* input,int f,int s)
{
    double first = (input[s].x -input[f].x)*(input[s].x -input[f].x);
    double second = (input[s].y - input[f].y)*(input[s].y - input[f].y);
    return sqrt(first+second);
    
}


int isleft(int p,int q,int index,point* input)
{
	int x1 = input[q].x - input[p].x;
	int y1 = input[q].y - input[p].y;
	int x2 = input[index].x - input[p].x;
	int y2 = input[index].y - input[p].y;
	int value = (x1*y2) - (y1*x2);
	return value;
}

void convex_hull(point* input,int n)
{
	int left = 0;
	vector<int> output;
	for(int i=1;i<n;i++)
	{
		if(input[i].x < input[left].x)
		{
			left = i;
		}
	}
	// we got the left most point
	int p = left;
	
	do
	{
		output.push_back(p);
		int q = (p+1)%n;// to get the random point
		for(int i=0;i<n;i++)
		{
			if(i==q)
			{
				continue;
			}
			if(isleft(p,q,i,input) > 0)
			{
				q=i;
			}
            else if(isleft(p,q,i,input)==0)
            {
                // check the farest point
                double q_v = distance(input,p,q);
                double i_v = distance(input,p,i);
               	if(q_v > i_v)
                {
                    continue;
                }
                else
                {
                    q = i;
                }
            }
		}
		p=q;
	}while(p!=left);

	for(int i=0;i<output.size();i++)
	{
		cout << input[output[i]].x << " " << input[output[i]].y << endl;
	}
	return ;



}

int main()
{
	int n;
	cin >> n;
	point* input = new point[n];
	for(int i=0;i<n;i++)
	{
		cin >> input[i].x;
	}
	for(int i=0;i<n;i++)
	{
		cin >> input[i].y;
	}
	convex_hull(input,n);
}