#include<bits/stdc++.h>
using namespace std;

struct paint
{
	long long start,cost,speed;

};


bool compare(struct paint a,struct paint b)
{
	if(a.start!=b.start)
	{
		return a.start < b.start;
	}
	return a.speed > b.speed;
}

long long solve(struct paint* Workers,long long N,long long D)
{
	sort(Workers,Workers+N,compare);
	long long total = Workers[0].cost;
	//int time = (Workers[1].start - Workers[0].start);
	
	int cur = 0;
	for(int i=1;i<N;i++)
	{
		D = D - ((Workers[cur].speed)*(Workers[i].start - Workers[i-1].start));
        if(D<=0)
        {
            break;
        }
		if(Workers[i].speed > Workers[cur].speed  && D > 0)
		{
			
			//D = D - (Workers[cur].speed*(Workers[i].start - Workers[cur].start));
			cur = i;
            total+=Workers[cur].cost;
		}

	}
	return total;

}



int main()
{
	long long N,D;
	cin >> N >> D;
	struct paint* Workers  = new struct paint[N];
	for(int i=0;i<N;i++)
	{
		cin >> Workers[i].start >> Workers[i].cost >> Workers[i].speed;
	}
	cout << solve(Workers,N,D) << endl;

	return 0;
}