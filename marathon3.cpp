#include "bits/stdc++.h"
using namespace std;
typedef pair<int,int> ii;
typedef vector<long long> vi;
typedef vector<ii> vii;
#define mkp make_pair
#define f first
#define s second
#define pb push_back
const int INF = 1e9+10;
const int MAXN = 1e5+10;
int price[MAXN];
int strength[MAXN];
vector<pair<int,ii>> adj[MAXN];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N,M,K,T;
	cin >> N >> M >> K >> T;
	for(int i=1;i<=M;i++)
	{
		int u,v,d,t;
		cin >> u >> v >> d >> t ;
		adj[u].emplace_back(v,mkp(d,t));
		adj[v].emplace_back(u,mkp(d,t));
	}
	for(int i=1;i<=K;i++)
	{
		cin >> price[i] >> strength[i] ;
	}
	int st=1 , ed = 2e5 , mid=0;
	while(st<=ed)
	{
		mid = (st+ed)/2;
		vi dist(N+5,INF);
		dist[1]=0;
		priority_queue<ii,vector<ii>,greater<ii>> pq;
		pq.emplace(mkp(0,1));
		while(!pq.empty())
		{
			ii now = pq.top();
			pq.pop();
			int d1 = now.first;
			int n1 = now.second;
			if(d1>dist[n1]) continue;
			for(auto op : adj[n1])
			{
				int d2=op.s.s;
				int n2=op.f;
				if(dist[n2]>dist[n1]+d2 && op.s.f<=mid)
				{
					dist[n2]=dist[n1]+d2;
					pq.emplace(dist[n2],n2);
				}
			}
		}
		if(dist[N]<=T) ed = mid-1;
		else st = mid+1 ;
	}
	int ans = INF;
	for(int i=1;i<=K;i++)
	{
		if(strength[i]>=mid) ans = min(ans , price[i]);
	}
	if(ans!=INF) cout << ans;
	else cout << "-1";

	//AC
}