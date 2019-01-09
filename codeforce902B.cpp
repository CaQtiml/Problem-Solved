#include "bits/stdc++.h"
using namespace std;
const int ct = 15000;
bool vis[ct];
int sc[ct] , col[ct];
vector<int> adj[ct];
int cnt=0;
void dfs(int u)
{
	vis[u]=1;
	if(col[u]!=sc[u])
	{
		col[u]=sc[u];
		cnt++;
		for(auto v : adj[u])
		{
			if(!vis[v]) col[v]=sc[u];
		}
	}
	else
	{
		for(auto v : adj[u])
		{
			if(!vis[v]) col[v]=sc[u];
		}
	}
	for(auto v : adj[u])
	{
		if(!vis[v]) dfs(v);
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=2;i<=n;i++)
	{
		int m;
		scanf("%d",&m);
		adj[i].emplace_back(m);
		adj[m].emplace_back(i);
	}
	memset(vis,0,sizeof(vis));
	memset(col,0,sizeof(col));
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&sc[i]);
	}
	dfs(1);
	cout << cnt;
}