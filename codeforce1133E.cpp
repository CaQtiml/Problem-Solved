#include "bits/stdc++.h"
using namespace std;
int arr[6000];
int dp[5010][5010];
int main()
{
	int n,k;
	cin >> n >> k;
	for(int i=1;i<=n;i++) cin >> arr[i];
	sort(arr+1,arr+1+n);
	int l=1;
	for(int i=1;i<=n;i++)
	{
		while(arr[i]-arr[l]>5) l++;
		for(int j=1;j<=k;j++)
		{
			dp[i][j]=max(dp[i-1][j],dp[l-1][j-1]+(i-l+1));
		}
	}
	cout << dp[n][k];
}