#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define pair<ll,ll> ii;
#define mkp make_pair
const int N = 1e5+10;
ll c[N];
vector<ll> adj[N];
void dfs(int u , int par , ll &pos , ll &neg )
{
	for(auto v : adj[u])
	{
		if(v != par)
		{
			ll poss=0 , negg=0;
			dfs(v,u,poss,negg);
			pos=max(pos,poss);
			neg=min(neg,negg);
		}
	}
	ll x = pos+neg ;
	ll y = c[u]-x;
	if(y<0) neg+=y;
	else pos+=y;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n ;
	for(int i=1;i<=n-1;i++)
	{
		int x,y;
		cin >> x >> y;
		adj[x].emplace_back(y);
		adj[y].emplace_back(x);
	}
	for(int i=1;i<=n;i++)
	{
		cin >> c[i];
	}
	ll pos=0 , neg=0; //positive and negative
	dfs(1,-1,pos,neg);
	cout << pos+abs(neg);
}