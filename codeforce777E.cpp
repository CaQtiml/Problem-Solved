#include "bits/stdc++.h"
using namespace std;
const int N = 1e5+50;
#define ii pair<int,int>
#define f first 
#define s second
#define iii pair<ii,int>
#define ll long long
#define mkp make_pair
iii adj[N],st[N];
ll ans=0,now=0,top=0;
bool cmp( iii a , iii b)
{
	if(a.f.s==b.f.s) return a.f.f > b.f.f;
	return a.f.s > b.f.s ;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n ;
	for(int i=1;i<=n;i++)
	{
		int a,b,h;
		cin >> a >> b >> h ;
		adj[i] = mkp(mkp(a,b),h);
	}
	sort(adj+1,adj+1+n,cmp);
	// for(int i=1;i<=n;i++)
	// {
	// 	cout << adj[i].f.f << " " << adj[i].f.s << " " << adj[i].s <<"\n" ;
	// }
	for(int i=1;i<=n;i++)
	{
		while(top && adj[i].f.s <= st[top-1].f.f )
		{
			top--;
			now-=st[top].s;
			//top--;
		}
		st[top] = adj[i] ;
		top++;
		now+=adj[i].s;
		ans=max(ans,now);
	}
	cout << ans ;
}