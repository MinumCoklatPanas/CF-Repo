#include <bits/stdc++.h>
using namespace std;

map<int,bool> ada;
int tab[1010];

int main()
{
//	freopen("input.txt","r",stdin);
	int n;
	int mx=0,mn=1e9+7;
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		int a;
		cin>>tab[i];
	}
	int cnt=0;
	sort(tab+1,tab+n+1);
	for (int i=2;i<=n;i++)
	 cnt+=tab[i]-tab[i-1]-1;
	cout<<cnt<<"\n";
}