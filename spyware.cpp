#include "bits/stdc++.h"
using namespace std;
#define ii pair<int,int>
#define f first
#define s second
int arr[(int)1e5+10];
vector<int> adj[(int)1e5+10];
vector<int> ti[(int)1e5+10];
bool visit[(int)1e5+10];
int main()
{
	int n,m,st;
	cin >> n >> m >> st;
	for(int i=1;i<=n;i++) cin >> arr[i];
	for(int i=1;i<=m;i++)
	{
		int u,v;
		cin >> u >> v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	queue<ii> q;
	q.emplace(st,0);
	while(!q.empty())
	{
		int u = q.front().f;
		int t = q.front().s;
		q.pop();
		if(visit[u]) continue;
		visit[u]=1;
		ti[t].emplace_back(u);
		for(auto v : adj[u])
		{
			if(!visit[v]) q.emplace(v,t+1);
		}
	}

	long long ans=0;
	//long long del=0;
	priority_queue<int> pq;
	for(int i=1;i<=n;i++)
	{
		if(!visit[i]) pq.emplace(arr[i]);
	}
	for(int i=n;i>=1;i--)
	{
		
		for(auto op : ti[i])
		{
			pq.emplace(arr[op]);
		}
		if(!pq.empty() && pq.top()>0)
		{
			ans+=pq.top();
			pq.pop();
		}
		//pq.clear();
	}
	cout << ans;
}