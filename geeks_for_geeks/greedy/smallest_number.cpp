 string smallestNumber(int S, int D){
        string output="";
        while(D>0 && S > 9)
        {
            output.push_back(9+'0');
            S-=9;
            D-=1;
        }
        if(D==0 && S!=0)
        {
            return "-1";
        }
        
        string temp="";
        if(D==1)
        {
            temp.push_back(S+'0');
            reverse(temp.begin(),temp.end());
            reverse(output.begin(),output.end());
            return temp + output;
        }
        D-=1;
        S-=1;
        temp.push_back(S+'0');
        D-=1;
        while(D>0)
        {
            temp.push_back(0+'0');
            D-=1;
        }
        temp.push_back(1+'0');
        reverse(temp.begin(),temp.end());
        reverse(output.begin(),output.end());
        return temp + output;
            
    }