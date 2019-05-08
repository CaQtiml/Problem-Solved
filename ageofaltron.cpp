#include "bits/stdc++.h"
using namespace std;
int dp[1005];
int cont[1005];
int arr[1005][1005];
int main()
{
	int n,m,k;
	int sum=0;
	cin >> n >> m >> k;
	int cnt=0;
	bool chk=false;
	int save1,save2;
	for(int i=1;i<=n;i++)
	{
		cnt=0;
		chk=0;
		for(int j=1;j<=m;j++)
		{
			int tt;
			cin >> tt;
			arr[i][j]=tt;
			if(tt==0)
			{
				if(chk==false)
				{
					chk=1;
					save1=j;
				}
				cnt++;
			}
			if(tt==1 && chk==true)
			{
				chk=0;
				save2=j;
				//cout << save1 << " " << save2 << "\n";
				cont[i]=max(cont[i],save2-save1);
			}
			if(chk and j==m)
			{
				chk=0;
				save2=j;
				//cout << save1 << " " << save2 << "\n";
				cont[i]=max(cont[i],save2-save1+1);
			}
		}
		dp[i]=cnt;
	}
	//cout << dp[1] << " " << dp[2];
	for(int i=n;i>=1;i--)
	{
		deque<int> pq;
		for(int j=1;j<=m;j++)
		{
			if(!arr[i][j])
			{
				pq.emplace_back(j);
			}
			while(!pq.empty() && j-k>=pq.front()) pq.pop_front();
			//cout << pq.size() << " " << sum << " " << k << " " << pq.size()+sum-k << "\n";
			if(pq.size()+sum>=k)
			{
				//cout << k ;
				//cout << "\n";
				cout << i ;
				exit(0);
			}
		}
		//for(auto op : pq) cout << op << " ";
		//cout << "\n";
		sum+=dp[i];
		//cout << sum << "\n";
	}
}