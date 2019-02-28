#include "bits/stdc++.h"
using namespace std;
map<int,vector<int>> mp;
//int a[100010];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n , q;
	cin >> n >> q;
	for(int i=1;i<=n;i++)
	{
		int r;
		cin >> r;
		//c[i]=r;
		mp[r].emplace_back(i);
	}
	for(int i=1;i<=q;i++)
	{
		int f,l,find;
		cin >> f >> l >> find;
		auto lo = lower_bound(mp[find].begin() , mp[find].end() , f);
		auto up = upper_bound(mp[find].begin() , mp[find].end() , l);
		int lower = lo-mp[find].begin();
		int upper = up-mp[find].begin()-1;
		cout << upper-lower+1 << "\n" ;
	}
}