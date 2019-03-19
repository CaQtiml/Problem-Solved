#include "bits/stdc++.h"
using namespace std;
#define ii pair<int,int>
#define vi vector<int>
#define f first
#define s second
class Unionfind
{
	private:
		vi p;
	public :
		Unionfind(int n)
		{
			p.assign(n,0);
			for(int i=0;i<n;i++) p[i]=i;
		}
		int fs(int i)
		{
			return p[i]==i ? i : (p[i]=fs(p[i]));
		}
		bool iss(int i,int j)
		{
			return (fs(i)==fs(j));
		}
		void us(int i,int j)
		{
			p[fs(i)]=fs(j);
		}
};

vector<pair<int,ii>> adj;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N,M,P;
	cin >> N >> M >> P;
	// Unionfind uf(N+10);
	for(int i=1;i<=M;i++)
	{
		int u,v,w;
		cin >> u >> v >> w ;
		adj.emplace_back(w,ii(u,v));
	}
	sort(adj.begin(),adj.end());
	// for(auto op : adj)
	// {
	// 	cout << op.f << "\n";
	// }
	vector<ii> ss;
	for(int i=1;i<=P;i++)
	{
		int u,v;
		cin >> u >> v;
		ss.emplace_back(u,v);
	}
	// for(auto op : ss)
	// {
	// 	cout << op.f << " " <<op.s << " " << "\n";
	// }
	int st=1,ed=1e9+5,ans=-1;
	while(st<=ed)
	{
		int mid=(st+ed)/2;
		//cout << "==" << mid << "\n";
		Unionfind uf(N+10);
		for(auto op : adj)
		{
			int c = op.f;
			int a = op.s.f;
			int b = op.s.s;
			//cout << c << "\n";
			if(c>=mid) break;
			if(!uf.iss(a,b))
			{
				uf.us(a,b);
			}
		}
		bool chk=true;
		for(auto op2 : ss)
		{
			int aa = op2.f;
			int bb = op2.s;
			//cout << uf.fs(aa) << " " << uf.fs(bb) << "\n";
			if(uf.fs(aa)==uf.fs(bb))
			{
				chk=false;
				break;
			}
		}
		if(chk)
		{
			//cout << "PASS\n";
			ans=max(ans,mid);
			st=mid+1;
		}
		else {ed=mid-1; /*cout << ed << "\n";*/}
	}
	if(ans==1e9+5
		) cout << -1;
	else cout << ans;
}