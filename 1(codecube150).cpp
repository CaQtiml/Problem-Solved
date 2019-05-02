#include "bits/stdc++.h"
using namespace std;
const int sz = 1e5+10;
const int INF = 1e9+29;
int dp[sz];
int cntwhite , cntturn;
int main()
{
	for(int i=0;i<sz;i++) dp[i]=INF;
	dp[1]=0;
	int n,T;
	cin >> n >> T;
	for(int i=1;i<=n;i++)
	{
		int num;
		cin >> num;
		if(dp[num]!=INF)
		{
			cntwhite++;
			cntturn+=dp[num];
		}
		else
		{
			for(int j=1;j*num<=(int)1e5;j++)
			{
				dp[j*num]=min(dp[j]+1,dp[j*num]);
			}
		}
	}
	cout << cntwhite << " ";
	if(T==2) cout << cntturn;
}