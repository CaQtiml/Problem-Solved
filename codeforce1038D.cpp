#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define int ll
int arr[500005];
int32_t main()
{
	int n;
	cin >> n;
	int sum=0;
	int mn=1e9+29;
	bool neg=0,pos=0;
	for(int i=1;i<=n;i++)
	{
		cin >> arr[i];
	}
	if(n==1)
	{
		cout << arr[1];
		exit(0);
	}
	for(int i=1;i<=n;i++)
	{
		sum+=abs(arr[i]);
		mn=min(mn,abs(arr[i]));
		if(arr[i]<=0) neg=1;
		if(arr[i]>=0) pos=1;
	}
	if(neg and pos) cout << sum;
	else cout << sum-2*mn;
}