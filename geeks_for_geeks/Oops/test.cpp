#include<bits/stdc++.h>
using namespace std;


class suni
{
	
	int* arr;

	public:
		
		suni()
		{
			arr = new int[6];
			for(int i=0;i<6;i++)
			{
				arr[i]=i;
			}
		}
		void display()
		{
			for(int i=0;i<6;i++)
			{
				cout << arr[i] << " ";
			}
			cout << endl;
		}

};

int main()
{
	suni a;
	suni* b = new suni();
	a.display();
	b->display();
	return 0;
}