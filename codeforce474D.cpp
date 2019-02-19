#include "bits/stdc++.h"
using namespace std;
#define ll long long
const int N = 1e5+10;
const int mod = 1e9+7;
ll dp[N];
ll sum[N];
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=N-2;i++)
	{
		if(i<k) dp[i]=1;
		else if(i==k) dp[i]=2;
		else dp[i]=(dp[i-1]+dp[i-k])%mod; 
	}
	for(int i=1;i<=N-2;i++)
	{
		if(i==1) sum[i]=dp[i];
		sum[i]=(sum[i-1]+dp[i])%mod;
		//sum[i]%=mod;
	}
	for(int i=1;i<=n;i++)
	{
		int st,ed;
		scanf("%d%d",&st,&ed);
		ll ans = (sum[ed]-sum[st-1]+mod)%mod;
		//ans+= (ans<0) ? mod : 0 ;
		cout << ans << "\n";
		// printf("%lld\n",(sum[ed]-sum[st-1])%mod);
	}
	// for(int i=1;i<=n;i++)
	// {
	// 	int st,ed;
	// 	ll ans=0;
	// 	scanf("%d%d",&st,&ed);
	// 	for(int j=st;j<=ed;j++)
	// 	{
	// 		ans+=dp[j];
	// 		ans%=mod;
	// 	}
	// 	printf("%lld\n",ans%mod);
	// }
	
}