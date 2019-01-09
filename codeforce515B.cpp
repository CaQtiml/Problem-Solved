#include "bits/stdc++.h"
using namespace std;
//int pre[2000];
int main()
{
	//heater is in interval [pos-r+1,pos+r-1] last is pos+r-1 
	int n , r , allsum ;
	cin >> n >> r;
	//vector<int> a(n+10);
	int arr[2000];
	arr[0]=0;
	int last=0;
	int cnt=0;
	for(int i=1;i<=n;i++) scanf("%d",&arr[i]);
	while(last<n)
	{
		int pos=-1;
		for(int i=n;i>max(0,last-r+1);i--){ //use max(0,last-r+1) instead of using if else at last=0 and last>0
			if(arr[i]==1 && (i-r+1)-1 <= last)
			{
				pos=i;
				break;
			}
		}
		if(pos==-1) {
			cout << "-1";
			return 0;
		}
		cnt++;
		last=pos+r-1;
	} 
	printf("%d",cnt);

}