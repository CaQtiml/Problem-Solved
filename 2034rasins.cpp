#include "bits/stdc++.h"
using namespace std;
int arr[55][55] , dp[55][55] , best[55][55][55][55];
const int INF = 1e9+29; 
int solve(int r1,int c1,int r2,int c2)
{
	if(best[r1][c1][r2][c2]==-1)
	{
		if(r1==r2 && c1==c2) best[r1][c1][r2][c2]=0;
		else
		{
			int bestfrombefore = INF;
			for(int r=r1+1;r<=r2;r++)
			{
				int temp = solve(r1,c1,r-1,c2)+solve(r,c1,r2,c2);
				if(bestfrombefore>temp) bestfrombefore = temp ;
			}
			for(int c=c1+1;c<=c2;c++)
			{
				int temp = solve(r1,c1,r2,c-1) + solve(r1,c,r2,c2);
				if(bestfrombefore>temp) bestfrombefore = temp ;
			}
			int rasin = dp[r2][c2];
			if(r1>1) rasin-=dp[r1-1][c2];
			if(c1>1) rasin-=dp[r2][c1-1];
			if(r1>0 && c1>0) rasin+=dp[r1-1][c1-1];
			best[r1][c1][r2][c2]= bestfrombefore + rasin ;
		}
	}
	return best[r1][c1][r2][c2];
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int r,c;
	cin >> r >> c;
	for(int i=1;i<=r;i++)
	{
		for(int j=1;j<=c;j++)
		{
			cin >> arr[i][j];
		}
	}
	//memset(dp,-1,sizeof(dp));
	memset(best,-1,sizeof(best));
	//dp[1][1]=arr[1][1];
	for(int i=1;i<=r;i++)
	{
		for(int j=1;j<=c;j++)
		{
			dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+arr[i][j];
		}
	}
	cout << solve(1,1,r,c);
}