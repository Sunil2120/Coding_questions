#include<bits/stdc++.h>
using namespace std;


int main()
{
	unordered_map<string,string> hash;
	hash["Jan"]="01";
	hash["Feb"]="02";
	hash["Mar"]="03";
	hash["Apr"]="04";
	hash["May"]="05";
	hash["Jun"]="06";
	hash["Jul"]="07";
	hash["Aug"]="08";
	hash["Sep"]="09";
	hash["Oct"]="10";
	hash["Nov"]="11";
	hash["Dec"]="12";
	string input;
	getline(cin,input);
	string date = input.substr(0,2);
	cout << date << endl;
	if(date[1]=='s' || date[1]=='r' || date[1]=='n' || date[1]=='t')
	{
		cout << "hello" << endl;
		date = date.substr(0,1);
		date = "0"+date;
	}
	string year = input.substr(input.length()-4);
	string mon = input.substr(input.length()-8,3);
	string output = year+"-"+hash[mon]+"-"+date;
	cout << output << endl;
}