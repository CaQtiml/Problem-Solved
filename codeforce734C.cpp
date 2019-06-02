#include "bits/stdc++.h"
using namespace std;
#define int long long
int spd[200005];
int mspd[200005];
int ins[200005];
int mins[200005];
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m,k,x,s;
	cin >> n >> m >> k >> x >> s;
	for(int i=1;i<=m;i++) cin >> spd[i];
	for(int i=1;i<=m;i++) cin >> mspd[i];
	for(int i=1;i<=k;i++) cin >> ins[i]; //already sorted
	for(int i=1;i<=k;i++) cin >> mins[i]; //already sorted
	int ans = n*x;
	//spd[0]=x;
	for(int i=1;i<=k;i++) if(mins[i]<=s) ans=min(ans,x*(n-ins[i]));
	for(int i=1;i<=m;i++)
	{
		if(mspd[i]<=s)
		{
			int left = s-mspd[i];
			int pos = upper_bound(mins+1,mins+k+1,left) - (mins+1)  ;
			int temp=((n-ins[pos])*spd[i]);
			ans=min(ans,temp);
		}
	}
	cout << ans;
}