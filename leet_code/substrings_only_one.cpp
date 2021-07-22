#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007


int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		string input;
		cin >> input;
        long long left = 0;
		long long right = 0;
		long long total = 0;
        while(left <= right && right < input.size())
        {
            if(input[right]=='0')
            {
                left+=1;
                right+=1;
            }
            if(input[right]=='1')
            {
                left = right;
                while(input[right]=='1' && right < input.size())
                {
                    right++;
                }
                total += ((right - left)*(right - left + 1))/2;
                total = total%(MOD);
                left = right;
            }
        }
        cout << total << endl;
	}
}