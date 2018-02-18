#include <bits/stdc++.h>
using namespace std;

bool cmp(int a,int b)
{
	return (a>b);
}

int main()
{
	int tab[110];
	int n;
	cin>>n;
	int sum=0;
	for (int i=1;i<=n;i++)
	 {
	 	cin>>tab[i];
	 	sum+=tab[i];
	 }
	sort(tab+1,tab+n+1,cmp);
	int a=0;
	for (int i=1;i<=n;i+=2)
	{
		a+=tab[i];
	}
	int sisa=sum-a;
	cout<<abs(a-sisa)<<"\n";
}
