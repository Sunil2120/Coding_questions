#include<bits/stdc++.h>
using namespace std;

void split(vector<string>& words,string input)
{
	int n = input.size();
	int start = 0;
	for(int i=0;i<n && start < n;i++)
	{
		if(input[i]==' ')
		{
			words.push_back(input.substr(start,i-start));
			start = i+1;
		}
	}
	if(start < n)
	{
		words.push_back(input.substr(start));
	}

	for(int i=0;i<words.size();i++)
	{
		cout << words[i] << endl;
	}
	string temp = "a";
	for(int i=0;i<words.size();i++)
	{
		string suni = words[i];
		if(suni[0] =='a' || suni[0] =='e' || suni[0] =='i' || suni[0] =='o' || suni[0] =='u' || 
			suni[0] =='A' || suni[0] =='E' || suni[0] =='I' || suni[0] =='O' || suni[0] =='U')
		{
			suni = suni + "ma" + temp;
		}
		else
		{
			suni.push_back(suni[0]);
			suni = suni.substr(1);
			suni = suni + "ma" + temp;
		}
		cout << suni << " ";
		temp.push_back('a');
	}
	cout << endl;
	return ;
}


int main()
{
	string input;
	getline(cin,input);
	vector<string> words;
	split(words,input);
}