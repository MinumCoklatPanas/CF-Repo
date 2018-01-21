#include <bits/stdc++.h>
using namespace std;

bool square(int x)
{
//	cout<<x<<"\n";
	int akar=(int)sqrt(x);
//	cout<<akar*akar<<"\n";
	return (akar*akar==x);
}

int main()
{
	int n;
	cin>>n;
	int tab[1010];
	for (int i=1;i<=n;i++)
	 cin>>tab[i];
//	for (int i=1;i<=n;i++)
//	 cout<<tab[i]<<" ";
//	cout<<"\n";
	sort(tab+1,tab+n+1);
	for (int i=n;i>=1;i--)
	 {
//	 	cout<<tab[i]<<"\n";
	 	if (!square(tab[i]))
	 	{
	 		cout<<tab[i]<<"\n";
	 		return 0;
	 	}
	 }
}
