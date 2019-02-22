#include "bits/stdc++.h"
using namespace std;
#define ii pair<int,int>
#define CLR(a) memset(a,0,sizeof(a));
#define mkp make_pair
int ans=0;
bool visit[150];
vector<ii> adj[150];
//bool chk=false;
bool dfs(int u , int v , int color )
{
	if(visit[u]) return 1;
	visit[u]=true;
	if(u==v) return 1;
	for(auto op : adj[u])
	{
		if( op.second==color && !visit[op.first] )
		{
			//ans++;
			if(dfs(op.first , v , color)) return true ;
		}
	}
	return false;
}
int main()
{
	int n , m ;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v,c;
		scanf("%d%d%d",&u,&v,&c);
		adj[u].emplace_back(v,c);
		adj[v].emplace_back(u,c);
	}
	int q;
	cin >> q;
	//cout << q << "\n";
	while(q--)
	{
		int u , v;
		scanf("%d%d",&u,&v);
		//ans=0;
		for(int i=1;i<=100;i++) //problem's limit color is 100 colors.
		{
			CLR(visit); //see #define for more information
			//if(dfs(u,v,i)) ans++; 
			if(dfs(u,v,i)) ans++;
		}
		printf("%d\n",ans);
		ans=0;
	}
}