//linesweep
//similar as duriancompany codecube
#include "bits/stdc++.h"
using namespace std;
#define ii pair<int,int>
int main()
{
	int n,p;
	scanf("%d%d",&n,&p);
	vector<ii> event;
	for(int i=1;i<=n;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		if(a>b) swap(a,b);
		event.push_back({a,1}); //add person
		event.push_back({b,2}); //remove person
		//add before remove because it is close interval
	}
	sort(event.begin(),event.end());
	int cnt=0 , start = -1 , end = -1;
	for(auto e : event)
	{
		if(e.second == 1) //add person
		{
			cnt++;
			if(cnt == n) start = e.first ;
		}
		else
		{
			cnt--;
			if(cnt == n-1 && start != -1) end = e.first;
		}
	}
	if(start == -1) printf("-1");
	else if(p>=start && p<=end) printf("0");
	else if(p<start) printf("%d",start-p);
	else if(p>end) printf("%d",p-end);
}