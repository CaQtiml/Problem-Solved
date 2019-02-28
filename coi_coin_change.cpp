#include "bits/stdc++.h"
using namespace std;
const int N = 1e6+5;
const int INF = 1e9+10; 
int dp[N],par[N]; //dp[i]=amount of coin to make "i" baht
int c[12];
int ans[3][12];
//pair<int,int> p[11];
#define f first
#define s second
void cntcoin(int cash , int who , int n)
{
	while(cash!=0)
	{
		int r = par[cash];
		for(int i=1;i<=n;i++)
		{
			if(cash-c[i]==r)
			{
				ans[who][i]++;
				cash=r;
				break;
			}
		}
	}
}
int main()
{

	memset(dp,-1,sizeof(dp));
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int price , limit , N;
	cin >> price >> limit >> N ;
	dp[0]=0;
	for(int i=1;i<=N;i++) cin >> c[i] ;
	for(int i=1;i<=limit;i++)
	{
		for(int j=1;j<=N;j++)
		{
			if(c[j]<=i)
			{
				if(dp[i]==-1 || dp[i]!=-1 && dp[i]>dp[i-c[j]]+1)
				{
					dp[i]=dp[i-c[j]]+1;
					par[i]=i-c[j];
				}
			}
		}
	}
	// for(int i=1;i<limit;i++)
	// {
	// 	cout << dp[i] << " ";
	// }
	//cout << "\n";
	int pay=0 , change= 0 , total=INF;
	int mpay=0 , mchange=0;
	/*for(int i=0 ; i+price <= limit ; i++)
	{
		if(dp[i]+dp[i+price]<total)
		{
			pay=dp[i+price];
			mpay=i+price;
			change = dp[i];
			mchange = i ;
			total = pay + change;
		}
	}*/
	for(int i=price ; i <= limit ; i++)
	{
		if(dp[i]+dp[i-price]<total)
		{
			pay=dp[i];
			mpay=i;
			change = dp[i-price];
			mchange = i-price ;
			total = pay + change;
		}
	}
	cout << pay << " " << change << "\n" ;
	cntcoin(mpay,0,N);
	cntcoin(mchange,1,N);
	for(int i=0;i<=1;i++)
	{
		for(int j=1;j<=N;j++)
		{
			cout << ans[i][j] << " " ;
		}
		cout << "\n" ;
	}
}