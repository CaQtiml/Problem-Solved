#include "bits/stdc++.h"
using namespace std;
const int N = 5e5+10;
const int INF = 1e9+10;
int c[N];
int dp[N]; 
int main()
{
	memset(c,INF,sizeof(c));
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,k,d;
	cin >> n >> k >> d ;
	int nn=n;
	for(int i=1;i<=n;i++)
	{
		cin >> c[i] ;
	}

	sort(c+1,c+n+1);

	dp[0]=1; //we can make the group that have size equal 0
	int e=1;
	for(int i=1;i<=n;i++) //we want to consider "c[i]" as the first number of group
	{
		if(dp[i-1]){ // so, we need to check whether the previous number (c[i-1]) is the last number of the before group .
			while(e<=n && c[e]-c[i]<=d) //use to check the requirement
			{
				if(e-i+1>=k) dp[e]=1; // use to check the requirement
				e++;
			}
		}
	}
	cout << (dp[n] == 1 ? "YES" : "NO") << "\n" ;
	// for(int i=1;i<=n;i++)
	// {
	// 	cout << dp[i] << " ";
	// }
 }