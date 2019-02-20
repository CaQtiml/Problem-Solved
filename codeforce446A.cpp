#include "bits/stdc++.h"
using namespace std;
const int N = 1e5+5;
int a[N];
int dpl[N];
int dpr[N];
bool ch=false; //change
int main()
{
	int n;
	cin >> n;
	int ans=0; //ans=max
	//int p1=1,p2=1;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i-1]<a[i]) dpl[i]=dpl[i-1]+1;
		else dpl[i]=1;
		ans=max(ans,dpl[i]);
	}
	if(ans<n) ans++;
	for(int i=n;i>0;i--)
	{
		dpr[i]=(a[i]<a[i+1]) ? dpr[i+1] + 1 : 1;
		if(a[i+1]-a[i-1]>1)
		{
			ans=max(ans,dpl[i-1]+dpr[i+1]+1);
		}
	}
	cout << ans;
}