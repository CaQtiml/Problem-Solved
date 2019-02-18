#include "bits/stdc++.h"
using namespace std;
string s[70];
bool visit[60][60];
bool cycle = false;
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
int n,m;
void dfs(int x , int y , int fx , int fy , char color)
{
	if(x<0||x>=n||y<0||y>=m) return;
	if(s[x][y]!=color) return;
	if(visit[x][y])
	{
		cycle = true;
		return;
	}
	visit[x][y]=true;
	for(int i=0;i<4;i++)
	{
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(nx==fx && ny==fy) continue; //prevent making the cycle that have only 1 node
		dfs(nx,ny,x,y,color);
	}

}
int main()
{
	//int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	{
		cin >> s[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(!visit[i][j])
			{
				dfs(i,j,-1,-1,s[i][j]);
			}
		}
	}
	cout << (cycle ? "Yes" : "No" ) ;
}