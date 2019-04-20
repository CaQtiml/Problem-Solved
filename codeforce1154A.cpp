#include "bits/stdc++.h"
using namespace std;
int dp[5];
int main()
{
	for(int i=1;i<=4;i++) cin >> dp[i];
	sort(dp+1,dp+5,greater<int>());
	int a=dp[1]-dp[2];
	int b=dp[1]-dp[3];
	int c=dp[1]-a-b;
	cout << a << " " << b << " " << c;
}