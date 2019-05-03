#include "bits/stdc++.h"
using namespace std;
const int sz = 1e6+10;
const int INF = 1e9+29;
int tower[sz],ans[sz];
int main()
{
	int n;
	cin >> n;
	for(int i=1;i<=n;i++) cin>>tower[i];
	deque<int> q;
	//q.emplace_back(0);
	for(int i=1;i<=n;i++)
	{
		//int pass=0;
		while(!q.empty()&&tower[i]>=tower[q.back()]) q.pop_back();
		if(q.empty()) q.emplace_front(0);
		ans[i]+=(i-q.back());
		q.emplace_back(i);
	}

	q.clear();

	q.emplace_back(n+1);
	for(int i=n;i>=1;i--)
	{
		//int pass=0;
		while(!q.empty()&&tower[i]>=tower[q.back()]) q.pop_back();
		//q.emplace_front(n);
		if(q.empty()) q.emplace_front(n+1);
		ans[i]+=(q.back()-i);
		q.emplace_back(i);
	}

	for(int i=1;i<=n;i++) cout << ans[i]-1 << " ";
}