#include <iostream>
#include<queue>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    queue<char> Q;
	    int* arr = new int[26]();
	    for(int i=0;i<n;i++)
	    {
	        char temp;
	        cin >> temp;
	        arr[temp-'a']+=1;
	        Q.push(temp);
	        while(Q.size() >0 && arr[Q.front()-'a']>1)
	        {
	            Q.pop();   
	        }
	        if(Q.size()==0)
	        {
	            cout << -1 << " ";
	        }
	        else
	        {
	            cout << Q.front() << " ";
	        }
	    }
	    cout << endl;
	}
	return 0;
}