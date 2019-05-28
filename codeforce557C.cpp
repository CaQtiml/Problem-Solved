#include "bits/stdc++.h"
using namespace std;
#define ii pair<int,int>
#define f first
#define s second
const int MAXS = 1e5+10;
ii p[MAXS];
int presum[MAXS];
int postsum[MAXS];
int main()
{
	int n;
	cin >> n;
	for(int i=1;i<=n;i++) cin >> p[i].f;
	for(int i=1;i<=n;i++) cin >> p[i].s;
	sort(p+1,p+n+1);
	for(int i=1;i<=n;i++) presum[i]=presum[i-1]+p[i-1].s;
	for(int i=n;i>=0;i--) postsum[i]=postsum[i+1]+p[i].s;
	multiset<int> ms;
	int ans = 1e9+29;
	for(int i=1;i<=n;i++)
	{
		int j=i+1;
		while(j<=n && p[j].f == p[j-1].f) j++;
		int sum = presum[i]+postsum[j];
		int k = j-i-1;
		for(auto it = ms.begin() ; it!=ms.end() and k ; it++)
		{
			k--;
			/*
			don't use sum-=*it and ms.insert(p[i].s) 
			We need to use -5 before -1
			"sum-=*it and ms.insert(p[i].s)" will use -1 before -5.
			*/
			sum+=*it;
		}
		ans=min(ans,sum);
		while(i!=j)
		{
			ms.insert(-p[i].s);
			i++;
		}
		i--;
	}
	cout << ans;
}