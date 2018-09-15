#include <bits/stdc++.h>
using namespace std;

vector<int> tab;

int main()
{
//	freopen("input.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,k;
	cin>>n>>k;
	for (int i=0;i<n;i++)
	{
		int a;
		cin>>a;
		tab.push_back(a);
	}
	sort(tab.begin(),tab.end());
//	reverse(tab.begin(),tab.end());
	int cnt=0;
	for (int i=0;i<n;i++)
	{
		if (k<0) break;
		cnt+=(tab[i]<=k);
		k-=tab[i];
	}
	cnt-=(k>0);
	cout<<cnt<<"\n";
}