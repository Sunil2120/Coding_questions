#include<bits/stdc++.h>
using namespace std;

int main()
{
	// freopen("rectin.txt","r",stdin);
	// freopen("rectout.txt","w",stdout);
	float x1,y1,x2,y2;
	cin >> x1 >> y1 >> x2 >> y2;
	float x3,y3,x4,y4;
	cin >> x3 >> y3 >> x4 >>y4;
	float a,b,c,d;
	a = max(x1,x3);//left
	b = min(x2,x4);//right
	c = max(y1,y3);//bottom
	d = min(y2,y4);//top
	float area = 0;
	if(a < b && c < d)
	{
		area = (b-a)*(d-c);
	}

	float A1 = (x2-x1)*(y2-y1);
	float A2 =(x4-x3)*(y4-y3);

	cout << (A1+A2-area) << endl;

	return 0;
}