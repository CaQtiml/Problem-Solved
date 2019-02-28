#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define ii pair<int,int>
#define iii pair<ll,ii>
#define mkp make_pair
#define f first
#define s second
const ll INF = 1e17;
const int N = 1e4+10;
vector<ii> adj[N];
ll dist[N][10];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m,t,st,ed;
	cin >> n >> m >> t >> st >> ed ;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin >> u >> v >> w;
		adj[u].emplace_back(v,w);
		//adj[v].emplace_back(u,w);
	}
	for(int i=0;i<N;i++)
		for(int j=0;j<10;j++)
			dist[i][j]=INF;
	dist[st][1%t] = 0 ;
	priority_queue<iii,vector<iii>,greater<iii>> pq;
	pq.emplace(dist[st][1%t],mkp(st,1%t));
	while(!pq.empty())
	{
		iii now = pq.top();
		pq.pop();
		ll d1 = now.f;
		int n1 = now.s.f;
		int chk = now.s.s;
		if(d1>dist[n1][chk]) continue;
		for(auto op : adj[n1])
		{
			ll d2 = op.s;
			int n2 = op.f;
			if( dist[n2][(chk+1)%t] > dist[n1][chk] + d2 )
			{
				dist[n2][(chk+1)%t] = dist[n1][chk] + d2;
				pq.emplace( dist[n2][(chk+1)%t] , mkp( n2 , (chk+1)%t ) );
			}
		}
	}
	(dist[ed][0]==INF) ? cout << "-1" : cout << dist[ed][0] ;
}