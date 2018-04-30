#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll DP[100010];
ll frek[100010];

int main()
{
//	freopen("input.txt","r",stdin);
	int n;
	cin>>n;
	int mx=0;
	for (int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		++frek[k];
		mx=max(mx,k);
	}
	DP[1]=frek[1];
	for (int i=2;i<=mx;i++)
	 DP[i]=max(DP[i-2]+frek[i]*i,DP[i-1]);
	cout<<DP[mx]<<"\n";
}
