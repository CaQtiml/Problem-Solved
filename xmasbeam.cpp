#include "bits/stdc++.h"
using namespace std;
#define ii pair<int,int>
#define x first
#define y second
//vector<ii> coor;
int N,H;
bool cmp(ii a , ii b)
{
	return a.x<b.x;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int rob;
	cin >> rob;
	while(rob--)
	{
		cin >> N >> H;
		ii coor[N+10];
		for(int i=1;i<=N;i++)
		{
			cin >> coor[i].x >> coor[i].y;
		}
		sort(coor+1,coor+1+N,cmp);
		// for(int i=1;i<=N;i++)
		// {
		// 	cout << coor[i].x << " " << coor[i].y << "\n";
		// }
		deque<int> mxq,mnq;
		int a=1;
		int ans=1e9+29;
		for(int b=1;b<=N;b++)
		{
			while( !mxq.empty() && coor[b].y > coor[mxq.back()].y ) mxq.pop_back();
			mxq.emplace_back(b);
			while( !mnq.empty() && coor[b].y < coor[mnq.back()].y ) mnq.pop_back();
			mnq.emplace_back(b);
			//star can be placed in same x-coordinate i.e (2,1),(2,10)
			while( a<=b && coor[mxq.front()].y - coor[mnq.front()].y >= H )
			{
				ans=min(ans,coor[b].x - coor[a].x);
				if(mxq.front()==a) mxq.pop_front();
				if(mnq.front()==a) mnq.pop_front();
				a++;
			} 
		}
		if(ans==(int)1e9+29) cout << "-1\n";
		else cout << ans << "\n";
	}
}
//sliding window