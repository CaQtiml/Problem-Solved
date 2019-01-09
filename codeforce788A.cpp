#include "bits/stdc++.h"
using namespace std;
#define ll long long
ll a[200000];
ll b[200000];

int main()
{

	ll n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}

	for(int i=1;i<n;i++)
	{
		b[i]= abs(a[i]-a[i+1]);
	}
	ll sum1=0;
	ll sum2=0;
	ll maxsum=-1000000;
	for(int i=1;i<n;i++)
	{
		ll now=b[i];
		
		//parallel calculating between l is odd and l is even.
		
		if((i-1)%2==1) //use i-1 because we use index 1 as the start index.
		{
			now = -now;
		}
		sum1+=now;
		sum2-=now;

		if(sum1<0) sum1=0;
		if(sum2<0) sum2=0;
		maxsum = max(maxsum,sum1);
		maxsum = max(maxsum,sum2);


	}
	printf("%lld",maxsum);
}
