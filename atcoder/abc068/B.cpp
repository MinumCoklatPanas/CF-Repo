#include <iostream>
#include <algorithm>
using namespace std;

int bit(int x)
{
	int res=0;
	while (x>1)
	{
		x/=2;
		res++;
	}
	return res;
}

int main()
{
	int i,j,k,n,tab[10];
	tab[0]=1;
	for (i=1;i<=10;i++)
	 tab[i]=2*tab[i-1];
	cin>>n;
	cout<<tab[bit(n)]<<"\n";
}