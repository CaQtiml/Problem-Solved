#include "bits/stdc++.h"
using namespace std;
int dp[4];
int cnt=0;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i=1;i<=3;i++) cin>>dp[i];
	if(dp[1]==dp[2]&&dp[2]==dp[3]) 
	{
		cout << dp[1] << "\n" << dp[2] << "\n"<< dp[3] << "\n";
		exit(0);
	}
	for(int i=1;cnt<n;i++)
	{
		if(dp[1]==dp[2]&&dp[2]==dp[3]) 
		{
			cout << dp[1] << "\n" << dp[2] << "\n"<< dp[3] << "\n";
			exit(0);
		}
		//cout << dp[1] << " " << dp[2] << " "<< dp[3] << "\n";
		if(i%3==1)
		{
			//cout << "P1" << "\n";
			if(dp[1]>=dp[2]&&dp[1]>=dp[3]) {cnt++; continue;}
			if(dp[1]<dp[3]&&dp[2]<=dp[1]) 
			{
				dp[1]+=((dp[3]-dp[1])*2);
				cnt++;
				continue;
			}
			if(dp[1]<dp[2]&&dp[3]<=dp[1]) 
			{
				dp[1]+=((dp[2]-dp[1])*2);
				cnt++;
				continue;
			}
			if(dp[1]<dp[2]&&dp[1]<dp[3])
			{
				int mn=min(dp[2],dp[3]);
				dp[1]+=((mn-dp[1])*2);
				cnt++;
				continue;
			}
		}
		if(i%3==2)
		{
			//cout << "P2" << "\n";
			if(dp[2]>=dp[3]&&dp[2]>=dp[1]) {cnt++; continue;}
			if(dp[2]<dp[3]&&dp[1]<=dp[2]) 
			{
				dp[2]+=((dp[3]-dp[2])*2);
				cnt++;
				continue;
			}
			if(dp[2]<dp[1]&&dp[3]<=dp[2]) 
			{
				dp[2]+=((dp[1]-dp[2])*2);
				cnt++;
				continue;
			}
			if(dp[2]<dp[1]&&dp[2]<dp[3])
			{
				int mn=min(dp[1],dp[3]);
				dp[2]+=((mn-dp[2])*2);
				cnt++;
				continue;
			}
		}
		if(i%3==0)
		{
			//cout << "P3" << "\n";
			if(dp[3]>=dp[1]&&dp[3]>=dp[2]) {cnt++; continue;}
			if(dp[3]<dp[1]&&dp[2]<=dp[3]) 
			{
				dp[3]+=((dp[1]-dp[3])*2);
				cnt++;
				continue;
			}
			if(dp[3]<dp[2]&&dp[1]<=dp[3]) 
			{
				dp[3]+=((dp[2]-dp[3])*2);
				cnt++;
				continue;
			}
			if(dp[3]<dp[1]&&dp[3]<dp[2])
			{
				int mn=min(dp[1],dp[2]);
				dp[3]+=((mn-dp[3])*2);
				cnt++;
				continue;
			}
		}
	}
	cout << dp[1] << "\n" << dp[2] << "\n"<< dp[3] << "\n";
}