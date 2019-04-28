#include "bits/stdc++.h"
using namespace std;
int arr[300000];
//int p1=1,p2=n;
int ans=0;
vector<char> vec;
int main()
{
	int n;
	cin >> n;
	int now=0;
	char track='L';
	//int mn=1e9+29;
	int cnt=0;
	int left=1,right=n;
	for(int i=1;i<=n;i++)
	{
		cin >> arr[i];
	}
	while(left<=right)
	{
		int mn;
		//cout << left << " " << right << "\n";
		//cout << arr[left] << " " << arr[right] << "\n";
		
		//int mn=min(arr[left],arr[right]);
		if(arr[left]!=arr[right])
		{
			if(arr[left]<arr[right])
			{
				mn=arr[left];
				if(mn<=now)
				{
					mn=arr[right];
				}
			}
			else if(arr[left]>arr[right])
			{
				mn=arr[right];
				if(mn<=now)
				{
					mn=arr[left];
				}
			}
			if(now>=mn) break;

			if(mn==arr[left])
			{
				now=mn;
				left++;
				ans++;
				vec.emplace_back('L');
				track='L';
					//continue;
			}
			else
			{
				now=mn;
				right--;
				ans++;
				vec.emplace_back('R');
				track='R';
					//continue;
			}
		}
		else
		{
			int chkl=now , chkr=now , jj=0 , kk=0;
			while(arr[left+jj]>chkl && left+jj<=n)
			{
				//j++;
				chkl=arr[left+jj];
				jj++;
			}
			while(arr[right-kk]>chkr && right-kk>0)
			{
				//k++;
				chkr=arr[right-kk];
				kk++;
			}
			//cout << jj << " " << kk << "\n";
			if(jj>kk)
			{
				now=chkl;
				for(int i=1;i<=jj;i++) vec.emplace_back('L');
				ans+=jj;
				left+=jj;
			
			}
			else 
			{
				now=chkr;
				for(int i=1;i<=kk;i++) vec.emplace_back('R');
				ans+=kk;
				right-=kk;
				if(jj==kk) break;
			}
		}
		
		
		//cout << now << "\n";
	}
	// if(left==right)
	// {
	// 		//cout << "==" << arr[left]  << " " << now << "\n";
	// 	if(track=='L'&& arr[left]>now)
	// 	{
	// 			//cout << "PASS\n";
	// 		ans++;
	// 		vec.emplace_back('R');
	// 		left++;
	// 	}
	// 	else if(track=='R'&& arr[left]>now)
	// 	{
	// 			//cout << "PASS\n";
	// 		ans++;
	// 		vec.emplace_back('L');
	// 		left++;
	// 	}
	// }
	cout << ans << "\n";
	for(auto op : vec) cout << op;
}