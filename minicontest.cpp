#include "bits/stdc++.h"
using namespace std;
int dp[(int)1e5+5][5];
int pre[(int)1e5+5][5];
const int INF = 1e9+29;
int main()
{
	int n;
	cin >> n;
	for(int i=0;i<(int)1e5+5;i++)
	{
		for(int j=0;j<5;j++)
		{
			dp[i][j]=INF;
		}
	}
	for(int i=1;i<=n;i++)
	{
		char ch;
		cin >> ch;
		int color;
		if(ch=='X') color=0;
		if(ch=='B') color=1;
		if(ch=='W') color=2;
		dp[0][1]=0 , dp[0][2]=0 , dp[0][3]=0 ;
		for(int j=1;j<=3;j++)
		{
			if(color!=0&&color!=j)continue;
			for(int k=1;k<=3;k++)
			{
				if(j==k) continue;
				if(dp[i][j]>dp[i-1][k])
				{
					dp[i][j]=dp[i-1][k];
					pre[i][j]=k;
				}
			}
			if(j==3) dp[i][j]++;
		}
	}
	int st=-1, mn=INF;
	for(int i=1;i<=3;i++)
	{
		if(dp[n][i]<mn)
		{
			mn=dp[n][i];
			st=i;
		}
	}
	if(st==-1)
	{
		cout << "No Answer";
		exit(0);
	}
	stack<char> stk;
	for(int i=n;i>=1;i--)
	{
		if(st==1) stk.emplace('B');
		if(st==2) stk.emplace('W');
		if(st==3) stk.emplace('G');
		st=pre[i][st];
	}
	while(!stk.empty())
	{
		cout << stk.top();
		stk.pop();
	}
}