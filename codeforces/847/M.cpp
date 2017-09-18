#include <bits/stdc++.h>
using namespace std;

int main()
{
	int i,j,k,n;
	cin>>n;
	if (n==2)
	{
		cin>>j>>k;
		int ans=k+(k-j);
		cout<<ans<<"\n";
		return 0;
	}
	else
	 {
	 	int now;
	 	cin>>k;
	 	cin>>now;
	 	int diff=now-k;
	 	//cout<<diff<<" diff\n";
	 	bool cek=true;
	 	for (i=1;i<=n-2;i++)
	 	{
	 		cin>>k;
	 		int beda=k-now;
	 		if (beda!=diff)
	 		 cek=false;
	 		now=k;
		}
		int ans;
		if (!cek)
		 ans=now;
		else
		 ans=now+diff;
		cout<<ans<<"\n";
		return 0;
	 }
}