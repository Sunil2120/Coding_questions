#include<bits/stdc++.h>
using namespace std;

bool compare(pair<int,int> p1,pair<int,int> p2)
{
    return p1.first < p2.first;// increasing order of first element
}

int solve_(vector<int> start,vector<int> end)
{
    vector< pair<int,int> > v;
    for(int i=0;i<start.size();i++)
    {
        v.push_back(make_pair(start[i],end[i]));
    }
    sort(v.begin(),v.end(),compare);
    // for(int i=0;i<v.size();i++)
    // {
    //     cout << v[i].first << "--" << v[i].second << endl;
    // }
    int count =0;
   // vector<pair <int,int> > result;
    vector<int> result;
    vector< pair<int,int> > :: iterator it;
    vector< pair<int,int> > :: iterator jt;
    for(it=v.begin();it!=v.end();it++)
    {
        for(jt=v.begin();jt!=v.end();jt++)
        {
            if(it->first >= jt->first && it->first <= jt->second)
            {
                count++;
            }
        }
        //result.push_back(make_pair(it->first,count));
        result.push_back(count);
        count=0;
    }
    // vector< pair<int,int> > :: iterator kt;
    // for(kt=result.begin();kt!=result.end();kt++)
    // {
    //     cout << kt->first<< " " << kt->second << endl;
    // }
    return *max_element(result.begin(),result.end()) ;
}
int main()
{
    int n;
    cin >> n;
    vector<int> start;
    vector<int> end;
    // for(int i=0;i<5;i++)
    // {
    //     int x ;
    //     int y;
    //     cin >> x;
    //     cin >> y;
    //     start.push_back(x);
    //     end.push_back(y);
    // }
    for(int i=0;i<n;i++)
    {
        int x;
        cin >> x;
        start.push_back(x);
    }
    for(int i=0;i<n;i++)
    {
        int y;
        cin >> y;
        end.push_back(y);
    }
    cout << solve_(start,end) << endl;
    return 0;
}