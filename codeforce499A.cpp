#include "bits/stdc++.h"
using namespace std;
int main()
{

	int n,k;
	scanf("%d%d",&n,&k);
	char a[100];
	scanf("%s",a);
	vector<int> ch;
	for(int i=0;i<n;i++)
	{
		int n = a[i]%96;
		ch.emplace_back(n);
	}
	sort(ch.begin(),ch.end());
	// for(auto u : ch)
	// {
	// 	printf("%d ",u);
	// }
	// printf("\n");
	int cnt=0;
	int sum=0;
	for(int i=0;i<n;i++)
	{
		if(cnt==k) break;
		if(i==0)
		{
			sum+=ch[0];
			cnt++;
			continue;
		}
		for(int u=i;u<n;)
		{
			if(ch[u]-ch[i-1]<2) u++;
			else if(ch[u]-ch[i-1]>=2)
			{
				i=u;
				sum+=ch[i];
				cnt++;
				break;
			}
		}
	}
	//printf("%d %d",cnt,sum);
	if(cnt==k) printf("%d",sum);
	else printf("-1");
}