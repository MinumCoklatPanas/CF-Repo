#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int tab[1010];
	for (int i=1;i<=n;i++)
	 cin>>tab[i];
	sort(tab+1,tab+n+1);
	cout<<tab[(n+1)/2]<<"\n";
}
