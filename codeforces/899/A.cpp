#include <bits/stdc++.h>
using namespace std;

int main()
{
//	freopen("input.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	int satu=0,dua=0;
	for (int i=1;i<=n;i++)
	{
		int a;
		cin>>a;
		satu+=(a==1);
		dua+=(a==2);
	}
	int mn=min(satu,dua);
	int ans=mn;
	satu-=mn;
	if (satu>0)
	 ans+=satu/3;
	cout<<ans<<"\n";
}
