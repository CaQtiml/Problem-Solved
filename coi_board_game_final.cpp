#include "bits/stdc++.h"
using namespace std;
bool visit[600][600][10];
char arr[600][600];
//int dist[600][600];
#define ii pair<int,int>
#define f first 
#define s second
const int INF = 1e9+29;
int sol = INF;
queue<pair<ii,ii>> q;
void process(int x,int y,int key,int dist)
{
	if(arr[x][y]=='.' && !visit[x][y][key])
	{
		q.emplace(ii(key,dist+1),ii(x,y));
	}
	if(arr[x][y]=='E' && !visit[x][y][key])
	{
		sol=min(sol,dist+1);
	}
	if(arr[x][y]=='j' && !visit[x][y][key])
	{
		q.emplace(ii(key|1,dist+1),ii(x,y));
	}
	if(arr[x][y]=='b' && !visit[x][y][key])
	{
		q.emplace(ii(key|2,dist+1),ii(x,y));
	}
	if(arr[x][y]=='p' && !visit[x][y][key])
	{
		q.emplace(ii(key|4,dist+1),ii(x,y));
	}
	if(arr[x][y]=='J' && !visit[x][y][key])
	{
		if(key==1 || key==3 || key==5 || key==7)
		{
			q.emplace(ii(key,dist+1),ii(x,y));
		}
	}
	if(arr[x][y]=='B' && !visit[x][y][key])
	{
		if(key==2 || key==3 || key==6 || key==7)
		{
			q.emplace(ii(key,dist+1),ii(x,y));
		}
	}
	if(arr[x][y]=='P' && !visit[x][y][key])
	{
		if(key==4 || key==5 || key==6 || key==7)
		{
			q.emplace(ii(key,dist+1),ii(x,y));
		}
	}
}
int main()
{
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin >> arr[i][j];
			if(arr[i][j]=='S')
			{
				q.emplace(ii(0,0),ii(i,j));
				arr[i][j]='.';
			}
		}
	}
	
	while(!q.empty())
	{
		int key= q.front().f.f;
		int dist = q.front().f.s;
		int x = q.front().s.f;
		int y = q.front().s.s;
		q.pop();
		if(visit[x][y][key]) continue;
		visit[x][y][key]=1;
		process(x+1,y,key,dist);
		process(x-1,y,key,dist);
		process(x,y+1,key,dist);
		process(x,y-1,key,dist);
	}
	if(sol==INF) cout <<"-1";
	else cout << sol;
}