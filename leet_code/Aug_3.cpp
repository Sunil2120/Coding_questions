#include<bits/stdc++.h>
using namespace std;


bool check_palindrome(string input)
{

	int f = 0;
	int s = input.size()-1;
	if(f==s)
	{
		return true;
	}
	while(f<s)
	{
		if(input[f]!=input[s])
		{
			return false;
		}
		f++;
		s--;
	}
	return true;
}


int main()
{
	string input;
	getline(cin,input);
	string temp="";
	int* alpha = new int[26]();
	int* num = new int[10]();
	for(int i=0;i<input.size();i++)
	{
		// num
		if(  input[i]>=47 &&  input[i] <= 57)
		{
			// num[input[i]-'0']+=1;
			temp+=input[i];
			continue;
		}
		// small alpha
		else if( input[i]>=97 && input[i]<=122)
		{
			//alpha[input[i]-'a']+=1;
			temp+=input[i];
			continue;
		}
		// upper case alpha
		else if( input[i]>=65 && input[i]<=90)
		{
			//alpha[input[i]+32 - 'a']+=1;
			char suni = input[i]+32;
			temp+=suni;
			continue;
		}

	}
	cout << temp << endl;
	cout << check_palindrome(temp) << endl;
	return 0;
}