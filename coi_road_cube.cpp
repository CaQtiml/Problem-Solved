#include "bits/stdc++.h"
using namespace std;
int arr[105][10005];
int dp[105][10005];
int ans=-1e9;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N,M,K;
	int ans=-1;
	cin >> N >> M >> K;
	deque<int> q;
	vector<int> cmp;
	for(int i=1;i<=N;i++)
	{
		
		if(i==1)
		{
			for(int j=1;j<=M;j++)
			{
				cin >> arr[i][j];
			}
		}
		else
		{
			for(int j=1;j<=M;j++)
			{
				cin >> arr[i][j];
				arr[i][j]+=cmp[j-1];
				if(i==N) ans=max(ans,arr[i][j]);
			}
			
		}
		if(i<N)
		{
			q.clear();
			cmp.clear();
			//cout << cmp.size() << "\n";

			// Sliding Window Algorithm
			for(int j=1;j<M+(2*K+1);j++)
			{
				while(!q.empty() && j-(2*K+1)>=q.front()) q.pop_front();
				while(!q.empty() && arr[i][j]>=arr[i][q.back()]) q.pop_back();
				q.emplace_back(j);
				if(j>=K+1)
				{
					cmp.emplace_back(arr[i][q.front()]);
				}
			}
			//
		}
	}
	cout << ans;
}