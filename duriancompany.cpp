//sweepline
//CR.Aquablitz
#include "bits/stdc++.h"
using namespace std;
#define ii pair<int,int>
int main()
{
	int n;
	scanf("%d",&n);
	vector<ii> event;
	for(int i=1;i<=n;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		event.push_back({b,1}); //remove people
		event.push_back({a,2}); //add people
	}
	sort(event.begin(),event.end());
	int cnt=0 , mx=0;
	for(auto e:event)
	{
		//Because b (people go out) is open interval
		//please remove before add people to prevent the exaggerated "mx" value
		if(e.second==1) //remove
		{
			cnt--;
		}
		else //add
		{
			cnt++;
			mx=max(mx,cnt);
		}
	}
	printf("%d",mx);
}