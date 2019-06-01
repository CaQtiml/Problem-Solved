#include "bits/stdc++.h"
using namespace std;
#define ii pair<int,int>
#define f first
#define s second
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
		return fs(i)==fs(j);
	}
	void us(int i,int j)
	{
		p[fs(i)]=fs(j);
	}
};
vector<pair<int,ii>> edge;
int ant[100005];
int check[100005];
int main()
{
	int n,m,k;
	cin >> n >> m >> k;
	for(int i=1;i<=n;i++)
	{
		int t;
		cin >> t;
		ant[i]=t;
	}
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin >> u >> v >> w;
		edge.emplace_back(w,ii(u,v));
	}
	sort(edge.begin(),edge.end(),greater<pair<int,ii>>());
	int st=1,ed=1e9+10,ans=0,cnt=0;
	while(st<=ed)
	{
		int mid = (st+ed)>>1;
		UnionFind uf(n+10);
		int i=0;
		for(auto op : edge)
		{
			int c = op.f;
			int a = op.s.f;
			int b = op.s.s;
			if(c<=mid)
			{
				cnt=m-i;
				break;
			}
			if(!uf.iss(a,b))
			{
				uf.us(a,b);
			}
			i++;
		}
		bool q=true;
		for(int i=1;i<=n;i++)
		{
			if(check[ant[i]]==0) check[ant[i]] = uf.fs(i);
			else if(check[ant[i]]!=uf.fs(i)) q=0;
		}
		if(q)
		{
			st=mid+1;
			ans=cnt;
		}
		else ed=mid-1;
		memset(check,0,sizeof(check));
	}
	cout << ans;
}