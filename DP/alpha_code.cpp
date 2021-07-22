#include<bits/stdc++.h>
using namespace std;


// recursive o(2**n)

int alpha(int *arr,int size)
{
	if(size==0 || size==1)
	{
		return 1;
	}

	int output = alpha(arr,size-1);
	if((arr[size-2]*10 + arr[size-1]*1) <=26)
	{
		output+=alpha(arr,size-2);
	}
	return output;
}


// dp recursive  o(2n)

int alpha2(int* arr,int size,int* output)
{
	if(size==0 || size==1)
	{
		return 1;
	}
	if(output[size] > 0)
	{
		return output[size];
	}

	int p = alpha2(arr,size-1,output);
	if((arr[size-2]*10 + arr[size-1]*1) <=26)
	{
		p+=alpha2(arr,size-2,output);
	}
	output[size]=p;
	return p;
}

 // DP iterative solution o(n)
int alpha3(int *arr,int size)
{
	int* output = new int[size+1]();
	output[0
	output[1]]=1;=1;
	for(int i=2;i<=size;i++)
	{
		output[i] = output[i-1];
		if((arr[i-2]*10 + arr[i-1]) <=26)
		{
			output[i]+=output[i-2];
		}
	}
	int ans = output[size];
	delete [] output;
	return ans;

}

#include <bits/stdc++.h>
using namespace std;

long long alpha_(string input)
{
	long long * output = new long long[input.size()+1]();
	output[0]=1;
	output[1]=1;
	for(long long i=2;i<=input.size();i++)
	{
		output[i]=output[i-1];
		if(((input[i-2] - '0')*10 + (input[i-1] - '0')) <=26)
		{
			output[i]+=output[i-2];
		}
	}

	long long ans = output[input.size()];
	delete []output;
	return ans;
}

int main()
{
	// int n;
	// cin >> n;
	// int* arr = new int[n];
	// for(int i=0;i<n;i++)
	// {
	// 	cin >> arr[i];
	// }
	// cout << alpha3(arr,n) << endl;
	// cout << alpha(arr,n) << endl;
	// int* output = new int[n+1]();
	// cout << alpha2(arr,n,output) << endl;
	string input;
	int count =0;
	int m = (pow(10,9)+7);
	cin >> input;
	while(input!="0")
	{
		int suni = 0;
		for(int i=0;i<input.size();)
	    {
	    	if(input[i]=='0')
	    	{
	    		int j=i;
	    		int c=0;
	    		while(input[i]=='0')
		        {
		        	c++;
		            i++;
		        }
		        string s = input.substr(0,i);
		        int x;
		        //cout << s << endl;
		        x=stoi(s);
		        
		        if(x > 26)
		        {
		        	cout << "0" << endl;
		        	//cin >> input ;
		        	suni = 1;
		        	break;
		        }
		        else
		        {
		        	cout << "1" << endl;
		        	//cin >> input;
		        	suni = 1;
		        	break;
		        }

		    }
		    else
		   	{
		   		i++;
		   	}    
	    }
	    if(suni == 0)
	    {
	    	cout << alpha_(input) << endl;
	    }
	    cin >> input ;
	}
	return 0;
}