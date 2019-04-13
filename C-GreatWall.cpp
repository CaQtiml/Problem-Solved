#include "bits/stdc++.h"
using namespace std;
const int SZ = 1e5+5;
int wall[SZ] , qs[SZ];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,w,k;
	cin >> n >> w >> k;
	for(int i=1;i<=n;i++) cin >> wall[i];
	int st=0,ed=1e9,ans=1e9+29;
	while(st<=ed)
	{
		int mid=(st+ed)>>1;
		int cnt=0;
		memset(qs,0,sizeof(qs));
		for(int i=1;i<=n;i++)
		{
			qs[i]+=qs[i-1];
			int chk = wall[i]+qs[i];
			if(chk>mid)
			{
				qs[i]-=chk-mid;
				qs[min(i+w,n+1)] += chk-mid;
				cnt += chk-mid;
			}
		}
		if(cnt<=k)
			{
				ans=min(ans,mid);
				ed=mid-1;
			}
		else st=mid+1;
	}
	cout << ans;
}