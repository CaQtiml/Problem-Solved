#include "bits/stdc++.h"
using namespace std;
const int INF = 1e9+29;
#define f first
#define s second
int dp[2010][305];
#define ii pair<int,int>
vector<pair<int,ii>> adj[400];
int main()
{
	int n,m,k,st,ed;
	cin >> n >> m >> k >> st >> ed;
	for(int i=1;i<=m;i++)
	{
		int u,v,c,w;
		cin >> u >> v >> c >> w;
		adj[u].emplace_back(v,make_pair(c,w));
		adj[v].emplace_back(u,make_pair(c,w));
	}
	for(int i=0;i<2010;i++)
	{
		for(int j=0;j<305;j++)
		{
			dp[i][j]=-INF;
		}
	}
	dp[0][st]=0;
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(auto v : adj[j])
			{
				if(i-v.s.s<0) continue;
				dp[i][j]=max(dp[i][j],dp[i-v.s.s][v.f]+v.s.f);
			}
		}
	}
	int ans=-INF;
	for(int i=0;i<=k;i++)
	{
		ans = max(ans,dp[i][ed]);
	}
	if(ans<0) cout << "Impossible";
	else cout << ans;
}