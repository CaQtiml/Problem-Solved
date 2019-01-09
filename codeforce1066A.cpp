#include "bits/stdc++.h"
using namespace std;
int main()
{
	int q;
	cin >> q;
	while(q--)
	{
		int L,v,l,r;
		scanf("%d%d%d%d",&L,&v,&l,&r);
		int ans=(L/v)-((r/v)-((l-1)/v));
		printf("%d\n",ans);
	}
}