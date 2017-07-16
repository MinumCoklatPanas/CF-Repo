#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(int x,int y)
{
	return (x>y);
}

int main()
{
	int k,n,sum,tab[100];
	cin>>n>>k;
	int i;
	for (i=1;i<=n;i++)
	 cin>>tab[i];
	sort(tab+1,tab+n+1,cmp);
	sum=0;
	for (i=1;i<=k;i++)
	 sum+=tab[i];
	cout<<sum<<"\n";
}