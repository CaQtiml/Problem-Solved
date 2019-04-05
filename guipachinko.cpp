#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define f first
#define s second
ll qs[100005];
#define ii pair<int,int>
vector<int> adj[100005];
vector<ii> e[100005];
ii op[100005];
int deg[100005] , mx[100005];
vector<int> order;

int dfs_findmax(int now)
{
	if(deg[now]==1) return mx[now]=now;
	else
	{
		int mxx=0;
		for(auto j : adj[now]) mxx=max(mxx,dfs_findmax(j));
		return mx[now]=max(mxx,now);
	}
}
void dfs_makeorder(int now)
{
	if(deg[now]>1) for(auto j : e[now]) dfs_makeorder(j.s);
	order.emplace_back(now);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;
	cin >> n >> m;
	int st;
	for(int i=1;i<=n;i++)
	{
		int u;
		cin >> u;
		if(u==0) st=i;
		else adj[u].emplace_back(i);
		deg[u]++ , deg[i]++;
	}
	for(int i=1;i<=m;i++)
	{
		cin >> op[i].f;
		if(op[i].f!=3) cin >> op[i].s;
	}
	dfs_findmax(st);
	for(int i=1;i<=n;i++)
	{
		for(auto opp : adj[i]) e[i].emplace_back(mx[opp],opp);
		sort(e[i].begin(),e[i].end());
	}
	order.emplace_back(-1);
	dfs_makeorder(st);
	for(int i=1;i<=n;i++) qs[i]=qs[i-1]+order[i];
	int cnt=0;
	for(int i=1;i<=m;i++)
	{
		int a=op[i].f , b=op[i].s;
		if(a==1)
		{
			cnt=min(n,cnt+b);
			cout << order[cnt] << "\n" ;
		}
		if(a==2)
		{
			cnt=max(0,cnt-b);
		}
		if(a==3) cout << qs[cnt] << "\n" ;
	}
}