#include <bits/stdc++.h>
using namespace std;

vector<int> tab[15];

int kali(int x)
{
	int res=1;
	while (x>0)
	{
		if (x%10>0)
		res*=x%10;
		x/=10;
	}
	return (res<10 ? res : kali(res));
}

void init()
{
	for (int i=1;i<=1000000;i++)
	{
		int wat=kali(i);
		tab[wat].push_back(i);
	}
}

int main()
{
//	freopen("input.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	init();
	int q;
	cin>>q;
	while (q--)
	{
		int l,r,k;
		cin>>l>>r>>k;
		int bawah=lower_bound(tab[k].begin(),tab[k].end(),l)-tab[k].begin();
		int atas=upper_bound(tab[k].begin(),tab[k].end(),r)-tab[k].begin()-1;
//		cout<<bawah<<" "<<atas<<"\n";
//		cout<<tab[k][bawah]<<" "<<tab[k][atas]<<"\n";
		cout<<atas-bawah+1<<"\n";
	}
}
