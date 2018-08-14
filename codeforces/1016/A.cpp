#include <bits/stdc++.h>
using namespace std;

int main()
{
//	freopen("input.txt","r",stdin);
	int n,m;
	cin>>n>>m;
	int sisa=m;
	for (int i=1;i<=n;i++)
	{
		int a;
		cin>>a;
		int ans=0;
		int mn=min(a,sisa);
		sisa-=mn;
		a-=mn;
		if (sisa==0)
		{
			sisa=m;
			++ans;
		}
		ans+=a/m;
		sisa-=a%m;
		cout<<ans<<" ";
	}
	cout<<"\n";
}