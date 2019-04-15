#include "bits/stdc++.h"
using namespace std;
#define ii pair<int,int>
vector<ii> adj[100010];
#define iii pair<int,ii>
const int INF = 2e9;
vector<iii> edge;
#define f first
#define s second
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m,st,ed;
	cin >> n >> m >> st >> ed;
	int ans=0;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin >> u >> v >> w;
		adj[u].emplace_back(v,w);
		adj[v].emplace_back(u,w);
		ans+=w;
		edge.emplace_back(w,make_pair(u,v));
	}
	vector<int> dist(n+10,INF);
	vector<int> dist2(n+10,INF);
	priority_queue<ii,vector<ii>,greater<ii>> pq;
	pq.emplace(0,st);
	dist[st]=0;
	while(!pq.empty())
	{
		int node1 = pq.top().second;
		int d1 = pq.top().first;
		pq.pop();
		if(d1>dist[node1]) continue;
		for(auto v : adj[node1])
		{
			int node2 = v.f;
			int d2 = v.s;
			if(dist[node2]>dist[node1]+d2)
			{
				dist[node2]=dist[node1]+d2;
				pq.emplace(dist[node2],node2);
			} 
		}
	}
	// if(dist[ed]=INF) 
	// {
	// 	cout << "0";
	// 	exit(0);
	// }
	dist2[ed]=0;
	pq.emplace(0,ed);
	while(!pq.empty())
	{
		int node1 = pq.top().second;
		int d1 = pq.top().first;
		pq.pop();
		if(d1>dist2[node1]) continue;
		for(auto v : adj[node1])
		{
			int node2 = v.f;
			int d2 = v.s;
			if(dist2[node2]>dist2[node1]+d2)
			{
				dist2[node2]=dist2[node1]+d2;
				pq.emplace(dist2[node2],node2);
			} 
		}
	}
	//cout << ans;
	int del=INF;
	for(auto op : edge)
	{
		int u = op.s.f;
		int v = op.s.s;
		del=min(del,min(dist[u]+dist2[v],dist[v]+dist2[u]));
	}
	cout << ans-del;
}