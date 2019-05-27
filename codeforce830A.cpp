#include "bits/stdc++.h"
using namespace std;
int ps[4000],key[4000];
int main()
{
	int n,k,p;
	cin >> n >> k >> p;
	int ans=3e9+29;
	for(int i=1;i<=n;i++) cin >> ps[i];
	for(int i=1;i<=k;i++) cin >> key[i];
	sort(ps+1,ps+1+n);
	sort(key+1,key+1+k);
	for(int i=0;i<=k-n;i++)
	{
		int mn=-(3e9+29);
		for(int j=1;j<=n;j++)
		{
			mn=max(mn,(abs(ps[j]-key[i+j])+abs(p-key[i+j])));
		}
		ans=min(ans,mn);
	}
	cout << ans;
}