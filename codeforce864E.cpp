#include "bits/stdc++.h"
using namespace std;
const int N = 105;
const int M = 2005;
#define ii pair<int,int> //< < recovered time , #item > , < price , burned time > >
#define iii pair<ii,ii> 
#define f first
#define s second
#define mkp make_pair
iii adj[N];
int dp[M]; // dp[time]
vector<int> way[M];
bool cmp ( iii a , iii b )
{
	return a.s.s < b.s.s ;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		int t , d , p;
		cin >> t >> d >> p;
		// adj.emplace_back(t,mkp(p,d));
		adj[i]=mkp(mkp(t,i),mkp(p,d));
	}
	sort(adj+1,adj+1+n,cmp);
	/*for(auto it : adj)
	{
		cout << it.f.f << " " << it.s.f << " " << it.s.s << "\n";
	}*/
	for(int i=1;i<=n;i++)
	{
		for(int j=adj[i].s.s-1 ; j>=adj[i].f.f ; j--)
		{
			if( dp[j] < dp[j-adj[i].f.f] + adj[i].s.f ) //dp[timenow]=dp[timenow-recovered time] + price of this item
			{
				dp[j] = dp[j-adj[i].f.f] + adj[i].s.f; 
				way[j]= way[j-adj[i].f.f];
				way[j].emplace_back(adj[i].f.s);
			}
		}
	}
	int ans1=0;
	vector<int> ans2;
	for(int i=0;i<=M-1;i++)
	{
		if( dp[i] > ans1)
		{
			ans1=dp[i] ;
			ans2=way[i];
		}
	}
	cout << ans1 << "\n" << ans2.size() << "\n" ;
	for(auto op : ans2)
	{
		cout << op << " ";
	}
}