#include<bits/stdc++.h>
using namespace std;


void  solve(int n,long long* x,long long* y,long long* f)
{
	float* output = new float[n]();
	output[n-1] = f[n-1];
	float d_c1 = pow(pow((x[n-1]-x[n-2]),2) + pow((y[n-1] - y[n-2]),2),0.5);
	output[n-2]= (f[n-1]+f[n-2]) - d_c1;
	float max_ = INT_MIN;
	for(int i=n-3;i>=0;i--)
	{
		long long mx=-1,my=-1,mf=-1;
		float d_c = pow(pow((x[n-1]-x[i]),2) + pow((y[n-1] - y[i]),2),0.5);
		float direct = (f[n-1]+f[i]) - d_c;
		//cout << "d" << " " << direct << endl;
		for(int j=i+1;j<n-1;j++)
		{
			if(output[j] > max_)
			{
				max_ = output[j];
				mx = x[j];
				my = y[j];
				mf = f[j];
			}
		}
		//cout << mx << " " << my << " " << mf << " " << max_ << endl;
		float i_c = 0;
		float indirect = 0;
		if(mx!=-1 && my!=-1 && mf!=-1)
		{
			i_c = pow(pow((mx-x[i]),2) + pow((my - y[i]),2),0.5);
			indirect = ((f[i]) - i_c) + max_;

		}
		
		//cout << "i" << " " << indirect << endl;
		output[i] = max(direct,indirect);
		//cout << "to" << " " << output[i] << endl;
		max_ = INT_MIN;
	}

	std::cout << std::setprecision(6) << std::fixed;
	cout << output[0] << endl;
	return ;
}
int main()
{
	int n;
	cin >> n;
	long long* x = new long long[n];
	long long* y = new long long[n];
	long long* f = new long long[n];
	for(int i=0;i<n;i++)
	{
		cin >> x[i] >> y[i] >> f[i];
	}
	
	solve(n,x,y,f) ;
	return 0;
}