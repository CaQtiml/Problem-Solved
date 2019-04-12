#include "bits/stdc++.h"
using namespace std;
const int MAXN = 1e6+10;
int dpl[MAXN],dpr[MAXN],a[MAXN];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<n;i++)
	{
		if(a[i]>=dpl[i-1]) 
		{
			dpl[i]=a[i];
		}
		else if(a[i]<=dpl[i-1])
		{
			dpl[i]=dpl[i-1];
		}
	}
	for(int i=n-1;i>=1;i--)
	{
		if(a[i+1]>=dpr[i+1]) 
		{
			dpr[i]=a[i+1];
		}
		else if(a[i+1]<dpr[i+1])
		{
			dpr[i]=dpr[i+1];
		}
	}
	// for(int i=1;i<n;i++) cout << dpl[i] << " "; 
	// cout << "\n";
	// for(int i=1;i<n;i++) cout << dpr[i] << " "; 
	for(int i=1;i<n;i++)
	{
		cout << min(dpl[i],dpr[i]) << "\n";
	}
}