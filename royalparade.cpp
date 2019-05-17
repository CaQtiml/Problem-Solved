#include "bits/stdc++.h"
using namespace std;
#define ll long long
typedef  pair<ll,ll> ii ;
typedef  vector<ll> vi;
typedef  vector<pair<ll,ll>> vii;
#define INF 1e18+29
#define s second
#define f first
#define pb emplace_back
#define mkp make_pair
vector<ii> adj[150000];
ll dist[150000];
ll dist2[150000];
bool chk[150000];
void dijkstra(ll st,ll ed,ll n,ll dist[])
{
	for(int i=0;i<150000;i++) dist[i]=INF;
	priority_queue<ii,vector<ii>,greater<ii>> pq;
	pq.emplace(0,st);
	dist[st]=0;
	while(!pq.empty())
	{
		ll node1 = pq.top().s;
		ll distt = pq.top().f;
		pq.pop();
		if(distt>dist[node1]) continue;
		for(auto op : adj[node1])
		{
			ll weight = op.s;
			ll node2 = op.f;
			if(dist[node2]>dist[node1]+weight)
			{
				dist[node2] = dist[node1]+weight;
				pq.emplace(dist[node2],node2);
			}
		}
	}
	//return dist[ed];
}
int main()
{
	ll n,m;
	cin >> n >> m;
	for(int i=1;i<=m;i++)
	{
		ll u,v,w;
		cin >> u >> v >> w;
		adj[u].emplace_back(v,w);
		adj[v].emplace_back(u,w);
	}
	ll a,b,c,d;
	cin >> a  >> b >> c >> d;
	dijkstra(a,b,n,dist);
	dijkstra(b,a,n,dist2);
	//cout << dist2[5];
	ll royalmin = min(dist[b],dist2[a]);
	// if(royalmin!=INF)
	// {
	// 	//utc(dist[],dist2[],a,b,royalmin,n);
		//chk[a]=1;
		//chk[b]=1;
		for(int i=1;i<=n;i++)
		{
			//if(i!=a and i!=b)
			//{
				if(dist[i]+dist2[i]==royalmin)
				{
					chk[i]=1;
				}
			//}
		}
	// }
	for(int i=0;i<150000;i++) dist[i]=INF;
	priority_queue<ii,vector<ii>,greater<ii>> pq;
	pq.emplace(0,c);
	dist[c]=0;
	while(!pq.empty())
	{
		ll node1 = pq.top().s;
		ll distt = pq.top().f;
		pq.pop();
		if(distt>dist[node1]) continue;
		if(chk[node1]) continue;
		for(auto op : adj[node1])
		{
			ll weight = op.s;
			ll node2 = op.f;
			if(dist[node2]>dist[node1]+weight && chk[node2]==0)
			{
				dist[node2] = dist[node1]+weight;
				pq.emplace(dist[node2],node2);
			}
		}
	}
	if(dist[d]==INF) cout << "-1";
	else cout << dist[d];
}