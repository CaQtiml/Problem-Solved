#include "bits/stdc++.h"
using namespace std;
#define ii pair<int,int>
int red=0,blue=0;
const int N = 3e5;
vector<int> adj[N+10];
int c[N+10];
int ans=0;
ii dfs(int u , int par)
{
	int r=(c[u]==1),b=(c[u]==2);
	//cout << "=====>" << u << " " << par << "\n";
	for(auto v : adj[u])
	{
		if(v!=par)
		{
			auto tmp = dfs(v,u);
			if(tmp.first==red && tmp.second==0) {ans++;}
			if(tmp.first==0 && tmp.second==blue) {ans++;}
			r+=tmp.first;
			b+=tmp.second;
		}
	}
	//cout << "==" << u << " " << r << " " << b <<"\n";
	return make_pair(r,b);
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&c[i]);
		if(c[i]==1) red++;
		else if(c[i]==2) blue++;
	}
	for(int i=1;i<=n-1;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	//int ans=0;
	//cout << red << "\n" << blue;
	ans=0;
	dfs(1,-1);
	cout << ans;
}