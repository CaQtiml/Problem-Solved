#include "bits/stdc++.h"
using namespace std;
int arr[505][505];
#define ii pair<int,int>
#define f first
#define s second
bool visit[505][505];
int dist[505][505];
map<int,int> mp;
int ans=0;
int main()
{
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin >> arr[i][j];
		}
	}
	int di[2][2]={{0,1},{-1,0}};
	queue<ii> q;
	q.emplace(n,1);
	dist[n][1]=1;
	while(!q.empty())
	{
		int x=q.front().f;
		int y=q.front().s;
		q.pop();
		if(visit[x][y]) continue;
		visit[x][y]=true;
		mp[dist[x][y]]++;
		for(int i=0;i<2;i++)
		{
			int xx = x+di[i][0] , yy=y+di[i][1];
			if(xx<1||xx>n||yy<1||yy>m) continue;
			if(!visit[xx][yy] && arr[xx][yy]==0) 
			{
				dist[xx][yy]=dist[x][y]+1;
				q.emplace(xx,yy);
			}
		}
	}
	// for(int i=1;i<=n;i++)
	// {
	// 	for(int j=1;j<=m;j++)
	// 	{
	// 		cout << dist[i][j] << " ";
	// 	}
	// 	cout << "\n";
	// }
	//for(int i=1;i<=5;i++) cout << mp[i] << "\n";
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			ans+=mp[dist[i][j]];
		}
	}
	cout<<ans;
}
//probability