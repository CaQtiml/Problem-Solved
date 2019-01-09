#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define INF (ll)1e18
ll dp[130][130][130]; //dp[#tree][beauty][#color]
//ll dp[160];
int c[150];
ll v[150][150]; //[#tree][#color]
int main()
{
	//printf("CHECK-1\n");
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			//scanf("%lld",&v[i][j]);
			cin >> v[i][j];
			//cout << v[i][j] << "\n"; 
		}
	}
	//printf("CHECK0");
	for(int i=0;i<=120;i++)
	{
		for(int j=0;j<=120;j++)
		{
			for(int k=0;k<=120;k++)
			{
				dp[i][j][k]=INF; 
			}
		}
	}
	if(c[1]==0)
	{
		for(int i=1;i<=m;i++)
		{
			dp[1][1][i]=v[1][i];
			//cout << dp[1][1][i] << "\n";
		}
	}
	else 
	{
		dp[1][1][c[1]]=0;
	}
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=k;j++)
		{
			if(c[i]==0)
			{
				for(int a=1;a<=m;a++)
				{
					dp[i][j][a]=min(dp[i][j][a],dp[i-1][j][a]+v[i][a]);
					for(int prev=1;prev<=m;prev++)
					{
						if(prev!=a)
						{
							dp[i][j][a]=min(dp[i][j][a],dp[i-1][j-1][prev]+v[i][a]);
						}
					}
				}
			}
			
			else
			{
				dp[i][j][c[i]]=min(dp[i][j][c[i]],dp[i-1][j][c[i]]);
				for(int prev=1;prev<=m;prev++)
				{
					if(prev!=c[i])
					{
						dp[i][j][c[i]]=min(dp[i][j][c[i]],dp[i-1][j-1][prev]);
					}
				}
			}
		}
	}
	ll ans=1e18;
	for(int color=1;color<=m;color++)
	{
		ans=min(ans,dp[n][k][color]);
		//cout << dp[n][k][color] << "\n";
	}
	if(ans>=INF) cout << -1;
	else cout << ans;
	
}
//not complete