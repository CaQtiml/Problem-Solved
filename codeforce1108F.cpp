#include "bits/stdc++.h"
using namespace std;
#define ii pair<int,int>
#define vi vector<int>
#define f first
#define s second
const int N = 200005 ;
#define mkp make_pair
class Unionfind
{
	private :
		vi p;
	public :
		Unionfind(int n)
		{
			p.assign(n,0);
			for(int i=0;i<n;i++) p[i]=i;
		}
		int fs(int i)
		{
			return (p[i]==i) ? i : (p[i]=fs(p[i])) ;
		}
		bool iss(int i , int j)
		{
			return (fs(i)==fs(j));
		}
		void us(int i , int j)
		{
			p[fs(i)]=fs(j);
		}
};
vector<pair<int,pair<int,int>>> e ;
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	Unionfind uf(n+5);
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		e.emplace_back(w,mkp(u,v));
	}
	sort(e.begin(),e.end());
	int ans=0;
	for(int i=0;i<m;i++)
	{
		int j=i;
		while(j<m && (e[j].first==e[i].first)) j++;
		int cnt = j-i;
		//cout << cnt << "\n";
		for(int k=i;k<j;k++)
		{
			if( uf.fs(e[k].s.f) == uf.fs(e[k].s.s) ) cnt--;
		}
		//cout << cnt << "\n";
		for(int k=i;k<j;k++)
		{
			if( uf.fs(e[k].s.f) != uf.fs(e[k].s.s) )
			{
				uf.us(e[k].s.f , e[k].s.s);
				cnt--;
			}
		}
		ans+=cnt;
		i=j-1;
		//cout << cnt << "\n";
		//printf("============\n");
	}
	cout << ans;
}