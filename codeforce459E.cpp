#include "bits/stdc++.h"
using namespace std;
const int N = 3e5+5;
#define ii pair<int,int>
int dp[N] , temp[N] ;
vector<ii> adj[N];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//cout << "PASS0";
	int n,m;
	cin >> n >> m;
	//cout << "PASS";
	for(int i=1;i<=m;i++)
	{
		int u , v , w;
		cin >> u >> v >> w;
		adj[w].emplace_back(u,v);
	}
	for(int i=0;i<N;i++)
	{
		for(auto op : adj[i]) temp[op.second]=max(temp[op.second] , dp[op.first]+1);
		for(auto op : adj[i]) dp[op.second]=max(temp[op.second] , dp[op.second]);
	}
	//cout << "PASS3";
	int ans=0;
	for(int i=0;i<=n;i++)
	{
		ans=max(ans,dp[i]);
		//cout << dp[i] << " ";
	}
	cout << ans; 
}