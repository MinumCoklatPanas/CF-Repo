#include <bits/stdc++.h>
using namespace std;

map<int,int> power;
int tab[100010];
int DP[100010];

int main()
{
//	freopen("input.txt","r",stdin);
	int n;
	vector<int> cari;
	cin>>n;
	for (int i=1;i<=n;i++)
	 {
	 	int k;
	 	cin>>tab[i]>>k;
	 	power[tab[i]]=k;
	 }
	sort(tab+1,tab+n+1);
	DP[1]=0;
	cari.push_back(tab[1]);
	for (int i=2;i<=n;i++)
	{
//		cout<<i<<" i\n";
		int k=tab[i]-power[tab[i]];
//		cout<<k<<" k\n";
		int pos=lower_bound(cari.begin(),cari.end(),k)-cari.begin();
		int banyak=(int)cari.size()-pos;
		if (banyak)
		 DP[i]=DP[pos]+banyak;
		else
		 DP[i]=DP[i-1];
		cari.push_back(tab[i]);
	}
//	for (int i=1;i<=n;i++)
//	 cout<<DP[i]<<" ";
//	cout<<"\n";
	int res=DP[n];
	for (int i=n;i>=1;i--)
	{
		int sum=n-i+1+DP[i-1];
		res=min(res,sum);
	}
	cout<<res<<"\n";
}

