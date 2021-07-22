#include<bits/stdc++.h>
using namespace std;

void reorderSpaces(string text) 
{
        int n=text.length();
        int space = 0;
        int words = 0;
        for(int i=0;i<n;i++)
        {
            if(text[i]==' ')
            {
                space+=1;
            }
        }
        int i=0;
        vector<string> arr;
        while(i<n)
        {
            int check = 0;
            string temp;
            while(text[i]!=' ' && i<n)
            {
            	temp.push_back(text[i]);
                check = 1;
                i+=1;
            }
            if(temp.size()!=0)
            {
            	cout << temp << endl;
            	arr.push_back(temp);

            }
           
            if(check==1)
            {
                words+=1;
            }
            i+=1;
        }
        cout << space << " " << words << endl;
        int value = space/(words-1);
        int rem = space%(words-1);
        cout << rem << endl;
        string output="";
        for(int i=0;i<words;i++)
        {
        	output+=arr[i];
        	for(int j=0;j<value;j++)
        	{
        		output.push_back(' ');
        	}
        }
        for(int j=0;j<rem;j++)
        {
        	output.push_back(' ');
        }
        output.push_back('\0');
        cout << output << endl;
}

int main()
{
	string text;
	getline(cin,text);
	reorderSpaces(text);
	return 0;


}