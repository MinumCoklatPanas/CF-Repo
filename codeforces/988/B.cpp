#include <bits/stdc++.h>
using namespace std;

string tab[110];

bool cmp(string a,string b)
{
	if (a.length()==b.length()) return a<b;
	return a.length()<b.length();
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
//	freopen("input.txt","r",stdin);
	int n;
	cin>>n;
	for (int i=1;i<=n;i++)
	 cin>>tab[i];
	sort(tab+1,tab+n+1,cmp);
	for (int i=1;i<n;i++)
	{
		size_t a=tab[i+1].find(tab[i]);
		if (a==string::npos)
		{
			cout<<"NO\n";
			return 0;
		}
	}
	cout<<"YES\n";
	for (int i=1;i<=n;i++)
	{
		cout<<tab[i]<<"\n";
	}
}
