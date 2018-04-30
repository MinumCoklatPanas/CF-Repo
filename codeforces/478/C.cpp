#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
	ll tab[3];
	for (int i=0;i<3;i++)
	 cin>>tab[i];
	sort(tab,tab+3);
	if (tab[2]>2*(tab[0]+tab[1]))
	 cout<<(tab[0]+tab[1])<<"\n";
	else
	 cout<<(tab[0]+tab[1]+tab[2])/3<<"\n";
}
