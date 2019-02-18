#include "bits/stdc++.h"
using namespace std;
#define ii pair<int,int>
#define mkp make_pair
int maze[700][700];
bool visit[700][700];
int main()
{
	int r,c,k,rs,cs;
	cin >> r >> c >> k;
	int cnt=1;
	int cblk=0;
	for(int i=1;i<=r;i++)
	{
		for(int j=1;j<=c;j++)
		{
			char ch;
			scanf(" %c",&ch);
			if(ch=='#') maze[i][j]=2 , cblk++ ;
			if(ch=='.')
			{
				maze[i][j]=1;
				if(cnt==1)
				{
					rs = i ;
					cs = j ;
					cnt++ ;
				}
			}
		}
	}
	int limit = (r*c)-k-cblk;
	int di[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
	queue<ii> q;
	q.push(mkp(rs,cs));
	while(!q.empty() && limit>0)
	{
		ii now = q.front();
		q.pop();
		int x = now.first;
		int y = now.second;
		if(visit[x][y]) continue;
		visit[x][y]=true;
		maze[x][y]=3;
		limit--;
		for(int i=0;i<4;i++)
		{
			int xx = x + di[i][0];
			int yy = y + di[i][1];
			if(xx<1 || xx>r || yy<1 || yy>c) continue;
			if(!visit[xx][yy] && maze[xx][yy]==1)
			{
				q.push(mkp(xx,yy));
			}
			else if(!visit[xx][yy] && maze[xx][yy]==2) visit[xx][yy]=true;
		}
	}
	for(int i=1;i<=r;i++)
	{
		for(int j=1;j<=c;j++)
		{
			//printf("%d ",maze[i][j]);
			if(maze[i][j]==1) printf("X");
			if(maze[i][j]==2) printf("#");
			if(maze[i][j]==3) printf(".");
		}
		printf("\n");
	}
}