#include "bits/stdc++.h"
using namespace std;
const int sz = 3e5+10;
int deg[sz];
int loss[sz];
int cm[sz];
vector<int> adj[sz];
void dfs(int u)
{
	for(auto v : adj[u])
	{
		dfs(v);
	}
	if(deg[u]==0) loss[u]=1;
	else
	{
		if(!cm[u]) //min
		{
			for(auto v : adj[u])
			{
				loss[u]+=loss[v];
			}
		}
		else
		{
			loss[u]=1e9;
			for(auto v : adj[u])
			{
				loss[u]=min(loss[u],loss[v]);
			}
		}
	}
}
int main()
{
	int n;
	cin >> n;
	for(int i=1;i<=n;i++) cin >> cm[i];
	for(int i=2;i<=n;i++)
	{
		int tt;
		cin >> tt;
		deg[tt]++;
		adj[tt].emplace_back(i);
	}
	int leave=0;
	for(int i=1;i<=n;i++)
	{
		if(deg[i]==0) leave++;
	}
	dfs(1);
	cout << leave-loss[1]+1;
}