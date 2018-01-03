#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int tab[110];
	int mx=0,mn=1000;
	for (int i=1;i<=n;i++)
	 {
	 	cin>>tab[i];
	 	mx=max(mx,tab[i]);
	 	mn=min(mn,tab[i]);
	 }
	int PosMax,PosMin;
	for (int i=1;i<=n;i++)
	 if (tab[i]==mx)
	 {
	 	PosMax=i;
	 	break;
	 }
	for (int i=n;i>=1;i--)
	 if (tab[i]==mn)
	 {
	 	PosMin=i;
	 	break;
	 }
	if (PosMax<PosMin)
	 cout<<(PosMax-1)+(n-PosMin)<<"\n";
	else
	 cout<<(PosMax-1)+(n-PosMin)-1<<"\n";
}
