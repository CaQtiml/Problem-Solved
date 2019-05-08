#include "bits/stdc++.h"
using namespace std;
const int sz = 1e5+10;
const int INF = -1e9+29;
int lis1[sz], dp1[sz];
int lis2[sz], dp2[sz];
int tree[sz];
int main()
{
	int n;
	cin >> n;
	int ans=-1;
	for(int i=1;i<=n;i++) cin >> tree[i];
	memset(lis1,-1,sizeof(lis1));
	memset(lis2,-1,sizeof(lis2));
	for(int i=1;i<=n;i++)
	{
		int st=1,ed=n;
		while(st<=ed)
		{
			int mid=(st+ed)>>1;
			if(lis1[mid]==-1 || (lis1[mid]!=-1 and tree[i]<lis1[mid])) ed=mid-1;
			else st=mid+1;
		}
		lis1[st]=tree[i];
		ans=max(ans,st);
		dp1[i]=ans;
	}
	ans=-1;
	for(int i=n;i>=1;i--)
	{
		int st=1,ed=n;
		while(st<=ed)
		{
			int mid=(st+ed)>>1;
			if(lis2[mid]==-1 || (lis2[mid]!=-1 and tree[i]<lis2[mid])) ed=mid-1;
			else st=mid+1;
		}
		lis2[st]=tree[i];
		ans=max(ans,st);
		dp2[n-i+1]=ans;
	}
	// for(int i=1;i<=n;i++) cout << dp1[i] << " ";
	// 	cout << "\n";
	// for(int i=1;i<=n;i++) cout << dp2[i] << " ";
	// 	cout << "\n";
	ans=-1;
	for(int i=1;i<=n;i++)
	{
		ans=max(ans,dp1[i]+dp2[n-i]);
	}
	cout << ans;
}