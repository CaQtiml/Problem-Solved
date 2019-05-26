#include "bits/stdc++.h"
using namespace std;
const int MAX = 1e5+10;
int arr[MAX];
int dp[MAX];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin >> arr[i];
		dp[i]=dp[i-1]+20;
		int idx1 = upper_bound(arr+1,arr+1+i,arr[i]-90)-arr-1;
		//cout << idx1 << "\n";
		dp[i]=min(dp[i],dp[idx1]+50);
		int idx2 = upper_bound(arr+1,arr+1+i,arr[i]-1440)-arr-1;
		dp[i]=min(dp[i],dp[idx2]+120);
		cout << max(0,dp[i]-dp[i-1]) << "\n";
	}
}