#include "bits/stdc++.h"
using namespace std;
int arr[505][505];
bool chk[505][505];
//int dp[505][505];
stack<int> stk;
int n,m;
bool recur(int h,int now)
{
	if(h==n+1 && now>0) return 1;
	if(h==n+1 && now==0) return 0;
	chk[h][now]=1;
	for(int i=1;i<=m;i++)
	{
		if(!chk[h+1][now^arr[h][i]])
		{
			if(recur(h+1,now^arr[h][i]))
			{
				stk.push(i);
				return 1;
			}
		}
	}
	return 0;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin >> arr[i][j];
		}
	}
	if(recur(1,0)==false)
	{
		cout << "NIE";
		exit(0);
	}
	cout << "TAK\n";
	while(!stk.empty())
	{
		cout << stk.top() << " ";
		stk.pop();
	}
}