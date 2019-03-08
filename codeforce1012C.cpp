#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5001;
const int INF = 1e9;

int dp[MAXN][MAXN][2], a[MAXN], n;



int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) 
    {
    	scanf("%d", &a[i]);
    }
    for(int i = 0; i <= n; i++) {
    	for(int j = 0; j <= n; j++) {
    		dp[i][j][1] = INF;
    		dp[i][j][0] = INF;
    	}
    }
    dp[0][0][0]=0;
    dp[1][0][0]=0;
    dp[1][1][1]=0;
    for(int i=2;i<=n;i++)
    {
    	dp[i][0][0]=0;
    	for(int j=1;j<=(n+1)/2;j++)
    	{
    		dp[i][j][0] = min(dp[i-1][j][0],dp[i-1][j][1]+max(0,a[i]-a[i-1]+1));
    		dp[i][j][1] = min( dp[i-2][j-1][0]+max(0,a[i-1]-a[i]+1) , dp[i-2][j-1][1]+max(0,a[i-1]-min(a[i],a[i-2])+1) );
    	}
    }

    for(int i = 1; i <= (n + 1) / 2; i++) {
    	cout<< min(dp[n][i][0], dp[n][i][1]) << " ";
    }

}