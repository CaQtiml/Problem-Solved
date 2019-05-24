#include "bits/stdc++.h"
using namespace std;
int arr[(int)1e6+10];
int solve(int i , int j)
{
	if(i>=j) return 0;
	if(arr[i]==arr[j]) return solve(i+1,j-1);
	else if(arr[i]<arr[j])
	{
		arr[i+1]+=arr[i];
		return 1+solve(i+1,j);
	}
	else if(arr[i]>arr[j])
	{
		arr[j-1]+=arr[j];
		return 1+solve(i,j-1);
	}
}
int main()
{
	int n;
	cin >> n;
	for(int i=1;i<=n;i++) cin >> arr[i];
	cout << solve(1,n);
}
// https://oj.uz/submission/113280