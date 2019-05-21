#include "bits/stdc++.h"
using namespace std;
//#define int long long
#define ll long long
#define ii pair<int,int>
#define li pair<ll,int>
#define f first
#define s second
vector<pair<li,ii>> edge;
//vector<int> adj[100010];
//map<int,int> mp;
//map<int,ll> mpsum;
vector<li> ss;
vector<int> ans;
class UnionFind
{
private:
	vector<int> p;
public:
	UnionFind(int n)
	{
		p.assign(n,0);
		for(int i=0;i<n;i++) p[i]=i;
	}
	int fs(int i)
	{
		return p[i]==i ? i : p[i]=fs(p[i]);
	}
	bool iss(int i,int j)
	{
		return fs(i) == fs(j);
	}
	void us(int i,int j) //unionset
	{
		p[fs(i)]=fs(j);
	}
};
int main()
{
	int n,m,T;
	cin >> n >> m;
	//if(m==n-1)
	//ll allsum=0;
	UnionFind uf(n+10);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		ll w;
		cin >> u >> v >> w;
		edge.emplace_back(li(w,i),ii(u,v));
	}
	cin >> T;
	sort(edge.begin(),edge.end(),greater<pair<li,ii>>());
	ll partialsum=0;
	int tmpcnt=0;
	for(auto op : edge)
	{
		int u = op.s.f;
		int v = op.s.s;
		ll w = op.f.f;
		int ne = op.f.s;
		if(!uf.iss(u,v))
		{
			partialsum+=w;
			uf.us(u,v);
			ans.push_back(ne);
			tmpcnt++;
			//ss.insert(uf.fs(v));
			//mp[uf.fs(i)]+=w;
		}
		else if(uf.iss(u,v))
		{
			//tmpcnt++;
			ss.push_back(li(w,ne));
		}
	}
	sort(ss.begin(),ss.end(),greater<li>());
	int now=0;
	if(tmpcnt!=n-1 || m<=n-1)
	{
		cout << "-1";
		exit(0);
	}
	if(!ss.empty()) partialsum += ss[0].f;
	cout << partialsum  << "\n";
	if(T==2)
	{
		for(auto op : ans)
		{
			cout << op << " ";
		}
		if(!ss.empty()) cout << ss[0].s;
	}
}