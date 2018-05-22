#include <bits/stdc++.h>
using namespace std;

int tab[100010];

int main()
{
//	freopen("input.txt","r",stdin);
	int n;
	cin>>n;
	for (int i=1;i<=n;i++)
	 {
	 	cin>>tab[i];
	 	tab[i]+=tab[i-1];
	 }
	int m;
	cin>>m;
	while (m--)
	{
		int ask;
		cin>>ask;
		int pos=lower_bound(tab+1,tab+n+1,ask)-tab;
		cout<<pos<<"\n";
	}
}
