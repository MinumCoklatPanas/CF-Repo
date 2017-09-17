#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll tab[1000010];

void init()
{
	memset(tab,-1,sizeof(tab));
	for (int i=1;i<=1000000;i++)
	{
		int akar=(int)sqrt(i);
		if (akar*akar==i)
		 {
		 	tab[i]=4*akar;
		 	//cout<<i<<" i\n";
		 }
	}
	int akar;
	int simpan=-1;
	for (int i=1;i<=1000000;i++)
	{
		if (i==simpan){
			tab[i]=tab[i-1]+2;
			i+=akar-1;
			continue;
		}
		if (tab[i]!=-1)
		 {
		 	akar=(int)sqrt(i);
		 	simpan=i+1;
		 }
		else
		 {
			tab[i]=tab[simpan]+2;
		 }
	}
	for (int i=1;i<=1000000;i++)
	 {
	 	if (tab[i]==-1)
	 	 tab[i]=tab[i-1];
	 }
}

int main()
{
	int i,j,k,n;
	cin>>n;
	init();
	cout<<tab[n]<<"\n";
}
