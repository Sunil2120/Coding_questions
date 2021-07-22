
//https://leetcode.com/problems/permutation-sequence/

// time complexity (n*nlogn)
// 1 indexing
class Solution {
public:
    
    int fact(int n)
    {
        if(n==0 || n==1)
            return 1;
        return n*fact(n-1);
    }
    void solve(set<char>& s,string& temp,int n,int k)
    {
        cout << k << " " << temp << endl;
        if(n==1)
        {
            temp+=to_string(*s.begin());
            return ;
        }
        set<char> :: iterator it = s.begin();
        // i should divide n! into n blocks 
        //  n!/x = n;
        // x = n!/n;
        int block_size = fact(n-1);
        // now I should go to block where k is present
        int block = k/block_size;
        if((k%block_size) != 0)
        {
            //next block;
            block+=1;
        }
        for(int i=0;i<block-1;i++)
        {
            it++;
        }
        temp+=to_string(*it);
        s.erase(it);
        //k's new position would be
        k = k%block_size;
        if(k==0)
            k=block_size;
        solve(s,temp,n-1,k);
    }
    string getPermutation(int n, int k) {
        
        set<char> s;
        for(int i=1;i<=n;i++)
        {
            s.insert(i);
        }
        string temp="";
        solve(s,temp,n,k);
        return temp;
        
    }
};


// 0 indexing

class Solution {
public:
    
    int fact(int n)
    {
        if(n==0 || n==1)
            return 1;
        return n*fact(n-1);
    }
    void solve(int n,int k,set<char>& s,string& temp)
    {
        if(n==1)
        {
            temp.push_back(*s.begin());
            return ;
        }
        int block_size = fact(n-1);
        // 0 indexing
        int block = k/block_size;
        set<char> :: iterator it=s.begin();
        advance(it,block);
        temp.push_back(*it);
        s.erase(it);
        k = k%block_size;
        solve(n-1,k,s,temp);
        return ;
        
    }
    string getPermutation(int n, int k) {
        
        set<char> s;
        for(int i=1;i<=n;i++)
        {
            s.insert((i+'0'));
        }
        string temp="";
        solve(n,k-1,s,temp);
        return temp;
    }
};