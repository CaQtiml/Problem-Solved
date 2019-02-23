#include "bits/stdc++.h"
using namespace std;
const int N = 2e5+10;
const int mod = 1e9+7;
#define ll long long
ll dp[N];
int main()
{
	int r,g;
	scanf("%d%d",&r,&g);
	int H=floor(sqrt(2*(r+g)));
	while(((H*(H+1))/2)>r+g) H--;
	//cout << H << "\n" ;
	dp[0]=1;
	//cout << H << "\n";
	for(int h=1;h<=H;h++)
	{
		//printf("PASS\n");
		int all=(h*(h+1))/2; //total of block from lv.1 to lv.h
		for(int i=min(all,g);i>=h;i--)
		{
			if(all-i<=r) 
			{
				dp[i]=(dp[i]+dp[i-h])%mod;
			}
		}
	}
	int ans=0;
	for(int i=0;i<=g;i++)
	{
		if(((H*(H+1))>>1)-i<=r) ans=(ans+dp[i])%mod;
	}
	printf("%d",ans);
}