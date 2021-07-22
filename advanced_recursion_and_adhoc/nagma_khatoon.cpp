// Key Observations:

// If you shift very last digit 
// Q
//  times, consecutively then you end up with the initial number 
// n
//  itself,
// If you add 
// 1
//  to each digit 
// 10
//  times, you again end up with the original number.
// Order in which the above operations are done does not matter.
#include<bits/stdc++.h>
using namespace std;


// time complexity o(10*n)

int main()
{
	int n;
	cin >> n;
	string input;
	cin >> input;
	vector<string> output;
	for(int i=0;i<10;i++)
	{
		output.push_back(input);
		// pushing all it's combination
		for(int j=0;j<input.length();j++)
		{
			 output.push_back(input.substr(j)+input.substr(0,j));
		}
		// adding one to input
		for(int j=0;j<input.length();j++)
		{
			if(input[j]=='9')
			{
				input[j]='0';
			}
			else
			{
				input[j]++;
			}
		}
	}

	cout << *min_element(output.begin(),output.end()) << endl;
}