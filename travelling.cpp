#include "bits/stdc++.h"
const int INF = 1e9+29;
#define ii pair<int,int>
#define iii pair<int,ii>
#define f first
#define s second
using namespace std;
int apsp[205][205] , mustpass[20] , dist[20][(int)1<<16];
int main()
{
	for(int i=0;i<205;i++)
	{
		for(int j=0;j<205;j++)
		{
			if(i!=j) apsp[i][j]=INF;
		}
	}
	int n,m,k;
	cin >> n >> m >> k;
	for(int i=1;i<=k;i++) cin >> mustpass[i];
	mustpass[0]=1;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin >> u >> v >> w;
		apsp[u][v]=min(apsp[u][v],w);
		apsp[v][u]=min(apsp[v][u],w);
	}
	
	for(int pp=1;pp<=n;pp++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				apsp[i][j]=min(apsp[i][j],apsp[i][pp]+apsp[pp][j]);
			}
		}
	}


	for(int i=0;i<20;i++)
	{
		for(int j=0;j<(int)((1<<16));j++)
		{
			dist[i][j]=INF;
		}
	}
	dist[0][1]=0;
	priority_queue<iii,vector<iii>,greater<iii>> pq;
	pq.emplace(0,ii(0,1));
	while(!pq.empty())
	{
		int d1=pq.top().f;
		int u=pq.top().s.f;
		int state=pq.top().s.s;
		pq.pop();
		if(d1>dist[u][state]) continue;
		for(int op=1;op<=k;op++)
		{
			int newstate = state|(1<<op);
			if(dist[op][newstate]>dist[u][state]+apsp[mustpass[u]][mustpass[op]])
			{
				dist[op][newstate]=dist[u][state]+apsp[mustpass[u]][mustpass[op]];
				pq.emplace(dist[op][newstate],ii(op,newstate));
			}
		}
	}
	int ans=INF; 
	int finalstate=(1<<(k+1))-1;
	for(int op=1;op<=k;op++)
	{
		//cout << dist[op][finalstate] << "\n";
		ans=min(dist[op][finalstate]+apsp[mustpass[op]][n],ans);
	}
	cout << ans;
}