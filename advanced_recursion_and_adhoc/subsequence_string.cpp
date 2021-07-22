#include<bits/stdc++.h>
using namespace std;

int subsequence(string input,string output[])
{
	if(input.empty())
	{
		output[0]="";
		return 1;
	}
	string sub_string = input.substr(1);
	int sm = subsequence(sub_string,output);
	for(int i=0;i<sm;i++)
	{
		output[i+sm] =input[0] + output[i];
	}
	return 2*sm;

}


void subsequence2(string input,string output)
{
	if(input.empty())
	{
		cout << output << endl;
		return ;
	}
	subsequence2(input.substr(1),output);
	subsequence2(input.substr(1),output + input[0]);
}




int main()
{
	string input;
	cin >> input;
	int len = input.length();
	//string* output = new string[pow(2,len)];
	// int sub_count = subsequence(input,output);
	// for(int i=0;i<sub_count;i++)
	// {
	// 	cout << output[i] << endl;
	// }
	subsequence2(input,"");
	//delete []output;
	return 0;
}