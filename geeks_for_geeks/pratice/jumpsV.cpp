bool canReach(string s, int minJump, int maxJump) {
	int n=s.size();
	int* dp=new int[n]();
	if(s[n-1]=='0')
	{
		dp[n-1]=true;
	}
	vector<int> indices;
	if(dp[n-1]==true)
	{
		indices.push_back(n-1);
	}
	for(int i=n-2;i>=0;i--)
	{
		if(s[i]=='1')
		{
			continue;
		}
		bool check=false;
		for(int j=0;j<indices.size();j++)
		{
			if(dp[j]==false)
			{
				continue;
			}
			else
			{
				//i + minJump <= j <= min(i + maxJump, s.length - 1)
				if(i+minJump <=indices[j] && indices[j]<=min(i+maxJump,s.length-1))
				{
					check=check||dp[indices[j]];
				}
			}
		}
		dp[i]=check;
		if(dp[i])
		{
			indices.push_back(i);
		}
	}
	return dp[0];
        
}