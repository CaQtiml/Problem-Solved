#include "bits/stdc++.h"
using namespace std;
#define ll long long
int a[605];
ll qsum[605];
ll dp[605][605];
ll solve(int i , int j)
{
	if(i==j) return 0;
	if(dp[i][j]!=0) return dp[i][j];
	ll best=-1;
	for(int a=i;a<j;a++)
	{
		ll left = solve(i,a);
		ll right = solve(a+1,j);
		ll c = qsum[a]-qsum[i-1];
		ll d = qsum[j]-qsum[a];
		best=max(best,left+right+2*min(c,d)+max(c,d));
	}
	//dp[i][j]=best;
	return dp[i][j]=best;
}
int main()
{
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		qsum[i]=qsum[i-1]+a[i];
	}
	cout << solve(1,n);
}