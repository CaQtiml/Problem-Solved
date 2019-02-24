#include "bits/stdc++.h"
using namespace std;
const int N = 100100;
#define ii pair<int,int>
#define mkp make_pair
#define CLR(a) memset(a,0,sizeof(a));
#define f first
#define s second
int p[N],dist[N],visit[N];
vector<int> adj[N];
void dfs(int u , int par)
{
	for(auto v : adj[u])
	{
		if(v!=par)
		{
			dist[v]=dist[u]+1;
			dfs(v,u);
		}
	}
}
void dfs2(int u , int par , int d)
{
	if(d==0) return;
	for(auto v : adj[u])
	{
		if(v!=par)
		{
			visit[v]++;
			dfs2(v,u,d-1);
		}
	}
}
int main()
{
	int n , e , d ;
	scanf("%d%d%d",&n,&e,&d);
	for(int i=1;i<=e;i++)
	{
		scanf("%d",&p[i]);
	}
	for(int i=1;i<=n-1;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	//===========================================
	dfs(p[1],p[1]);
	int maxn=-1,mfar;
	for(int i=1;i<=e;i++)
	{
		if(maxn<dist[p[i]])
		{
			maxn=dist[p[i]];
			mfar=p[i];
		}
	}
	visit[mfar]++;
	dfs2(mfar,mfar,d);
	
	//===========================================
	
	CLR(dist) //for more information,go to #define zone
	dfs(mfar,mfar);
	maxn=-1;
	for(int i=1;i<=e;i++)
	{
		if(maxn<dist[p[i]])
		{
			maxn = dist[p[i]];
			mfar = p[i] ;
		}
	}
	visit[mfar]++;
	dfs2(mfar,mfar,d);

	//===========================================
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(visit[i]==2) cnt++;
		//printf("%d ",visit[i]);
	}
	printf("%d",cnt);
}