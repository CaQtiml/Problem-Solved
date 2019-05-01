#include "bits/stdc++.h"
using namespace std;
#define ll long long
ll arr[(int)2e5] , qs[(int)2e5];
ll fans(ll r1,ll r2,ll r3)
{
	ll c1=abs(r2-r1);
	ll c2=abs(r3-r1);
	ll c3=abs(r3-r2);
	return max(max(c1,c2),c3);
}
int main()
{
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> arr[i];
		qs[i]=qs[i-1]+arr[i];
	}
	ll ans=1e18+29;
	for(int i=1;i<=n-2;i++)
	{
		ll r1=qs[i]-qs[0];
		ll r2,r3;
		ll st=i+1 , ed=n-1;
		ll cmp=1e18+29;
		while(st<=ed)
		{
			ll mid=(st+ed) >>  1 ;
			ll t2=qs[mid]-qs[i];
			ll t3=qs[n]-qs[mid];
			if(abs(t2-t3)<cmp)
			{
				cmp=abs(t2-t3);
				r2=t2;
				r3=t3;
			}
			if(t2>t3) ed=mid-1;
			else st=mid+1;
		}
		ans=min(ans,fans(r1,r2,r3));
	}
	cout << ans;
}