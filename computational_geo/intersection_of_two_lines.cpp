// find the point that intersect two lines or two line segment
#include<bits/stdc++.h>
using namespace std;


int main()
{
	double x1,y1,x2,y2,x3,y3,x4,y4;
	cin >> x1 >> y1 >> x2 >> y2;
	double A1,B1,A2,B2,C1,C2;
	A1 = y2 - y1;
	B1 = (x1 - x2);
	C1 = A1*x1 + B1*y1;
	cin >> x3 >> y3 >> x4 >> y4;
	A2 = y4 - y3;
	B2 = (x3 - x4);
	C2 = A2*x3 + B2*y3;
	double deter = ((A1*B2) - (B1*A2));
	if(deter==0)
	{
		cout << "no point of intersection" << endl;
		return 0;
	}
	double x = ((C1*B2) - (C2*B1))/deter;
	double y = (C1 - A1*x)/B1;
	cout << "point of intersection " << x << " " << y << endl; 
	// checking for line segment
	// for line 1
	if(min(x1,x2) <= x  && x<= max(x1,x2) && min(y1,y2) <= y && y <= max(y1,y2))
	{

		if(min(x3,x4) <= x  && x<= max(x3,x4) && min(y3,y4) <= y && y <= max(y3,y4))
		{
			cout << "point of intersection " << x << " " << y << endl; 
			return 0;
		}

	}
	cout << "no point of intersection" << endl;
	return 0;	
}