#include "bits/stdc++.h"
using namespace std;
int a[150];
int cnt;
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	if(n>m)
	{
		printf("0");
		exit(0);
	}
	for(int i=1;i<=m;i++)
	{
		int temp;
		scanf("%d",&temp);
		a[temp]++;
	}
	vector<int> b;
	for(int i=0;i<150;i++)
	{
		if(a[i]>0)	b.emplace_back(a[i]);
	}
	//use bsearch to find the maximum number of days that can be survived.
	int l=1,r=1e9,ans=-1;
	while(l<=r)
	{
		int mid = (l+r)/2;
		//printf("%d\n",mid);
		cnt=0;
		for(auto i : b)
		{
			if(i/mid>0) cnt+=(i/mid);
			if(cnt>=n) break;
		}
		//if food is enough for "mid" day with "n" people then l=mid+1 
		if(cnt>=n) {ans=mid; l=mid+1;} 
		else r=mid-1;
	}
	printf("%d",ans);
}