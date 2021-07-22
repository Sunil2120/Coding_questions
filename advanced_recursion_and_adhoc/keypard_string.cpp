#include<bits/stdc++.h>
using namespace std;



int keypard_string(int num,string output[],map<int,string> keypard)
{
	if(num==0)
	{
		output[0]="";
		return 1;
	}
	int q = num/10;
	int r = num%10;
	int result = keypard_string(q,output,keypard);
	string* temp= new string[result];
	int count=keypard[r].size();
	int p=0;
	for(int i=0;i<result;i++)
	{
		temp[i]=output[i];
	}
	for(int i=0;i<keypard[r].size();i++)
	{
		for(int k=0;k<result;k++)
		{
			output[p]=temp[k] + keypard[r][i];
			p++;
		}
	}
	return p;

}


void keypard_string2(int num,string output,map<int,string> m)
{
	if(num==0)
	{
		cout << output << endl;
		return ;
	}
	int q=num/10;
	int r = num%10;
	for(int i=0;i<m[r].size();i++)
	{
		keypard_string2(q,output + m[r][i],m);
	}
	return ;
}
int main()
{
	int num;
	cin >> num;
	map<int,string> keypard;
	keypard[1]="abc";
	keypard[2]="def";
	keypard[3]="ghi";
	keypard[4]="jkl";
	keypard[5]="mno";
	keypard[6]="pqr";
	keypard[7]="stu";
	keypard[8]="vwx";
	keypard[9]="yz";
	string* output= new string[1000];
	// int result = keypard_string(num,output,keypard);
	// for(int i=0;i<result;i++)
	// {
	// 	cout << output[i] << endl;
	// }
	keypard_string2(num,"",keypard);
	return 0;
}