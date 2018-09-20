#include <bits/stdc++.h>
using namespace std;

int tab[110];
int frek[110];
queue<int> q;
string ans;

int main()
{
//	freopen("input.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	int dua=0;
	for (int i=1;i<=n;i++)
	{
		cin>>tab[i];
		frek[tab[i]]++;
		ans+='B';
	}
	int cnt=0;
	bool ada=0;
	int simpan=-1;
	for (int i=1;i<=n;i++)
	{
		cnt+=((frek[tab[i]]==1));
		dua+=((frek[tab[i]])==2);
		if ((frek[tab[i]]==1))
		 {
//		 	frek[tab[i]]=4;
		 	q.push(i);
		 }
		if ((frek[tab[i]]==3))
		 {
		 	ada=1;
		 	simpan=tab[i];
		 }
	}
	if ((cnt&1) && (cnt+dua==n))
	{
		cout<<"NO\n";
		return 0;
	}
	cout<<"YES\n";
	bool ya=1;
	if (!(cnt&1)){
	while (!q.empty())
	{
		if (ya)
		ans[q.front()-1]='A';
		q.pop();
		ya^=1;
	}
	}
	else
	{
//		for (int i=1;i<=7;i++)
//		 cout<<frek[i]<<" ";
//		cout<<"\n";
		for (int i=1;i<=n;i++)
		{
			if (frek[tab[i]]>2)
			{
//				cout<<i<<" "<<frek[tab[i]]<<"\n";
				ans[i-1]='A';
				break;
			}
		}
//		cout<<ans<<" ans\n";
		bool ya=1;
		while (!q.empty())
		{
//			cout<<q.front()<<" wat\n";
			if (!ya)
			ans[q.front()-1]='A';
			q.pop();
			ya^=1;
		}
	}
	cout<<ans<<"\n";
}