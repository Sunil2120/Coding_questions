#include<iostream>
using namespace std;


int main()
{

	int i=10;
	try
	{
		int a=0;
		if(a==0)
			throw "division error";
		i = i/a;
	}
	catch(string s)
	{
		cout << s << endl;
	}
	catch(...)
	{
		cout << "exception error" << endl;
	}
	cout << "end" << endl;
	return 0;
}