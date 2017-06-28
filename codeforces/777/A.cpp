#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
	long long i,j,k,n;
	long long tab[10][10];
	tab[1][0]=1;
	tab[1][1]=0;
	tab[1][2]=2;
	tab[2][0]=2;
	tab[2][1]=0;
	tab[2][2]=1;
	tab[3][0]=2;
	tab[3][1]=1;
	tab[3][2]=0;
	tab[4][0]=1;
	tab[4][1]=2;
	tab[4][2]=0;
	tab[5][0]=0;
	tab[5][1]=2;
	tab[5][2]=1;
	tab[0][0]=0;
	tab[0][1]=1;
	tab[0][2]=2;
	cin>>n;
	cin>>k;
	for (i=0;i<=2;i++)
	{
		if (tab[n%6][i]==k)
		{
			cout<<i<<"\n";
			return 0;
		}
	}
}
