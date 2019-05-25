#include "bits/stdc++.h"
using namespace std;
int mat[105][105];
int arr[105];
int main()
{
	int n;
	cin >> n;
	for(int i=1;i<n;i++) arr[i]=i;
	arr[n]=(n*(n-1))-(((n-1)*(n))/2);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			mat[i][j]=arr[i]*100000;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			mat[i][j]+=arr[j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cout << mat[i][j] << " ";
		}
		cout << "\n";
	}
}